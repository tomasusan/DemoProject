// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "Animation/CallAttackNotifyState.h"
#include "Animation/CloseComboAnimNotify.h"
#include "Animation/ComboAnimNotify12.h"
#include "Animation/CommoAnimNotify23.h"
#include "Animation/EndAvoidAnimNotify.h"
#include "Animation/EntryAnimNotify.h"
#include "Animation/HitLightBaseAnimNotify.h"
#include "Animation/OpenComboAnimNotify.h"
#include "Animation/OutAnimNotify.h"
#include "Animation/StartAvoidAnimNotify.h"
#include "Animation/StopDetectAnimNotify.h"
#include "BehaviorTree/Blackboard/BlackboardKey.h"
#include "Character/BaseCharacterMovementComponent.h"
#include "DemoProject/AnimUtils.h"
#include "DemoProject/MathUtils.h"
#include "Component/WeaponComponent.h"
#include "Weapon/BaseWeaponActor.h"

DEFINE_LOG_CATEGORY_STATIC(PlayerCharacterLog, All, All);

APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjInit): Super(
	ObjInit.SetDefaultSubobjectClass<UBaseCharacterMovementComponent>(ABaseCharacter::CharacterMovementComponentName))
{
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAnimation();

	WeaponComponent->CurrentRightHandWeapon = SpawnWeapon(WeaponComponent->RightHandWeapon, RightHandWeaponSocketName);
	WeaponComponent->CurrentLeftHandWeapon = SpawnWeapon(WeaponComponent->LeftHandWeapon, LeftHandWeaponSocketName);
	
}

void APlayerCharacter::Attack()
{
	Super::Attack();
	if (AttackAnim && CanAttack)
	{
		if (!ComboInfo.InAnim)
		{
			PlayAnimMontage(AttackAnim);
			SetCanMove(false);
			ComboInfo.CurrentWantCombo = 0;
			ComboInfo.CurrentInCombo = 0;
		}
		else
		{
			if (ComboInfo.CanCombo && !ComboInfo.WantCombo)
			{
				ComboInfo.WantCombo = true;
			}
		}
	}
}

void APlayerCharacter::ProAttack()
{
	if (ProAttackAnim)
	{
		if (!ComboInfo.InAnim)
		{
			PlayAnimMontage(ProAttackAnim);
			ComboInfo.CurrentInCombo = 0;
		}
		else
		{
			if (ComboInfo.CanCombo && !ComboInfo.WantCombo)
			{
				ComboInfo.WantCombo = true;
			}
		}
	}
}

void APlayerCharacter::StartSprint()
{
	//Super::StartSprint();
	float AnimLength = 0;
	ProcessDesireDirection();
	if (AvoidAnims[DesireDirection] && GetCanMove())
	{
		AnimLength = PlayAnimMontage(AvoidAnims[DesireDirection]);
	}
	ShiftDown = true;
	GetWorld()->GetTimerManager().SetTimer(SprintTimer, this, &APlayerCharacter::OnCheckShiftDown, AnimLength, false,
	                                       AnimLength);
}

void APlayerCharacter::EndSprint()
{
	Super::EndSprint();
	ShiftDown = false;
}

void APlayerCharacter::MoveForward(const float Val)
{
	Super::MoveForward(Val);
}

void APlayerCharacter::MoveRight(const float Val)
{
	Super::MoveRight(Val);
}

void APlayerCharacter::OpenCombo()
{
	ComboInfo.CanCombo = true;
}

void APlayerCharacter::CloseCombo()
{
	ComboInfo.CanCombo = false;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAction("Attack_Pro", IE_Pressed, this, &APlayerCharacter::ProAttack);
	}
}

void APlayerCharacter::LoadAttackNotifyState()
{
	const auto Notifies = AnimUtils::FindNotifyStatesByClass<UCallAttackNotifyState>(AttackAnim);
	UE_LOG(PlayerCharacterLog, Warning, TEXT("Load %d States"), Notifies.Num());
	
	for(const auto CallAttackNotify:Notifies)
	{
		CallAttackNotify->CallAttackDelegate.AddUObject(WeaponComponent, &UWeaponComponent::CallAttack);
		CallAttackNotify->EndAttackDelegate.AddUObject(WeaponComponent, &UWeaponComponent::EndAttack);
	}
}

void APlayerCharacter::InitAnimation()
{
	if (!AttackAnim)
	{
		return;
	}

	auto EntryAnimNotify = AnimUtils::FindNotifyByClass<UEntryAnimNotify>(AttackAnim);
	auto OutAnimNotify = AnimUtils::FindNotifyByClass<UOutAnimNotify>(AttackAnim);
	const auto WantCombo2Notify = AnimUtils::FindNotifyByClass<UComboAnimNotify12>(AttackAnim);
	const auto WantCombo3Notify = AnimUtils::FindNotifyByClass<UCommoAnimNotify23>(AttackAnim);
	const auto StopDetectNotify = AnimUtils::FindNotifyByClass<UStopDetectAnimNotify>(AttackAnim);


	for (const auto OpenComboAnimNotify : AnimUtils::FindNotifiesByClass<UOpenComboAnimNotify>(ProAttackAnim))
	{
		OpenComboAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::OpenCombo);
	}

	for (const auto CloseComboAnimNotify : AnimUtils::FindNotifiesByClass<UCloseComboAnimNotify>(ProAttackAnim))
	{
		CloseComboAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::CloseCombo);
	}

	for (const auto ProEntryNotify : AnimUtils::FindNotifiesByClass<UEntryAnimNotify>(ProAttackAnim))
	{
		ProEntryNotify->OnNotified.AddUObject(this, &APlayerCharacter::SetEntryAnim);
	}

	for (const auto ProOutAnimNotify : AnimUtils::FindNotifiesByClass<UOutAnimNotify>(ProAttackAnim))
	{
		ProOutAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::SetOutAnim);
	}


	for (const auto AvoidAnim : AvoidAnims)
	{
		UStartAvoidAnimNotify* StartAvoidAnimNotify = AnimUtils::FindNotifyByClass<UStartAvoidAnimNotify>(AvoidAnim);
		StartAvoidAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::OnStartAvoid);
		UEndAvoidAnimNotify* EndAvoidAnimNotify = AnimUtils::FindNotifyByClass<UEndAvoidAnimNotify>(AvoidAnim);
		EndAvoidAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::OnEndVoid);
	}


	check(EntryAnimNotify);
	check(OutAnimNotify);
	check(WantCombo2Notify);
	check(WantCombo3Notify);

	EntryAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::SetEntryAnim);
	OutAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::SetOutAnim);
	WantCombo2Notify->OnNotified.AddUObject(this, &APlayerCharacter::WantCombo2);
	WantCombo3Notify->OnNotified.AddUObject(this, &APlayerCharacter::WantCombo3);
	StopDetectNotify->OnNotified.AddUObject(this, &APlayerCharacter::OnStopDetectInput);

	EntryAnimNotify = AnimUtils::FindNotifyByClass<UEntryAnimNotify>(HitAnim_Light);
	OutAnimNotify = AnimUtils::FindNotifyByClass<UOutAnimNotify>(HitAnim_Light);

	EntryAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::SetEntryAnim);
	OutAnimNotify->OnNotified.AddUObject(this, &APlayerCharacter::SetOutAnim);

	LoadAttackNotifyState();
}

void APlayerCharacter::SetEntryAnim()
{
	ComboInfo.InAnim = true;
	ComboInfo.WantCombo = false;
	UE_LOG(PlayerCharacterLog, Warning, TEXT("Now Entry Anim"));
}

void APlayerCharacter::SetOutAnim()
{
	ComboInfo.InAnim = false;
	ComboInfo.CurrentWantCombo = -1;
	ComboInfo.CurrentInCombo = -1;
	ComboInfo.WantCombo = false;
	ComboInfo.CanCombo = false;
	SetCanMove(true);
	UE_LOG(PlayerCharacterLog, Warning, TEXT("Now Out Anim"));
}

void APlayerCharacter::AddCombo()
{
	ComboInfo.CurrentInCombo++;
}

void APlayerCharacter::OnStopDetectInput()
{
	ComboInfo.CanCombo = false;
}

void APlayerCharacter::WantCombo2()
{
	ComboInfo.CanCombo = true;
	ComboInfo.CurrentWantCombo = 1;
}

void APlayerCharacter::WantCombo3()
{
	ComboInfo.CanCombo = true;
	ComboInfo.CurrentWantCombo = 2;
}

void APlayerCharacter::OnStartAvoid()
{
	SetCanMove(false);
	CanAttack = false;
	ComboInfo.InAnim = true;
}

void APlayerCharacter::OnEndVoid()
{
	SetCanMove(true);
	CanAttack = true;
	ComboInfo.InAnim = false;
	ComboInfo.CanCombo = false;
	ComboInfo.WantCombo = false;
	ComboInfo.CurrentWantCombo = -1;
}

void APlayerCharacter::OnCheckShiftDown()
{
	if (ShiftDown)
	{
		SetIsSprint(true);
	}
}

template<typename T>
T* APlayerCharacter::SpawnWeapon(TSubclassOf<T> WeaponClass,FName SocketName)
{
	if(!GetWorld()) return nullptr;
	auto SocketLocation = GetMesh()->GetSocketLocation(SocketName);
	const auto CurrentWeapon = GetWorld()->SpawnActor<T>(WeaponClass);

	if(!CurrentWeapon) return nullptr;
	const FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, false);
	CurrentWeapon->AttachToComponent(GetMesh(), Rules, SocketName);

	return CurrentWeapon;
}

void APlayerCharacter::ProcessDesireDirection()
{
	const float Direction = GetMovementDirection();
	if (Direction >= -45 && Direction <= 45)
		DesireDirection = Front;
	else if (Direction > 45 && Direction <= 135)
		DesireDirection = Left;
	else if (Direction > 135 || Direction < -135)
		DesireDirection = Back;
	else if (Direction >= -135 && Direction < -45)
		DesireDirection = Right;
}
