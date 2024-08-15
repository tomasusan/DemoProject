// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

#include "BaseCharacterMovementComponent.h"
#include "GameFramework//SpringArmComponent.h"
#include "DemoProject/MathUtils.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(BaseCharacterLog, All, All);

// Sets default values
ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjInit): Super(
	ObjInit.SetDefaultSubobjectClass<UBaseCharacterMovementComponent>(ABaseCharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

float ABaseCharacter::GetMovementDirection() const
{
	const FVector VelocityNormal = GetVelocity().GetSafeNormal();

	// 获取角色前方的向量
	const FVector VectorForward = GetActorForwardVector();

	// 计算速度向量和角色前方向量之间的夹角
	const auto AngleBetween = FMath::Acos(FVector::DotProduct(VelocityNormal, VectorForward));

	// 计算速度向量和角色前方向量的叉积
	const auto Cross = FVector::CrossProduct(VelocityNormal, VectorForward);

	// 将夹角从弧度转换为度数，并乘以叉积的Z分量的符号
	return FMath::RadiansToDegrees(AngleBetween) * FMath::Sign(Cross.Z);
}

bool ABaseCharacter::IsMoving() const
{
	return !GetVelocity().IsNearlyZero();
	//return IsMovingForward || IsMovingRight;
}

// bool ABaseCharacter::IsFalling() const
// {
// 	return 
// }

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
		PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::LookUp);
		PlayerInputComponent->BindAxis("LookRight", this, &ABaseCharacter::LookRight);
		PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ABaseCharacter::Attack);
		PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacter::StartSprint);
		PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacter::EndSprint);
		PlayerInputComponent->BindAction("Impacted", IE_Pressed, this, &ABaseCharacter::OnImpacted);
	}
}

void ABaseCharacter::MoveForward(const float Val)
{
	if (!CanMove) return;
	IsMovingForward = !FMath::IsNearlyZero(Val);
	AddMovementInput(GetActorForwardVector(), Val);
}

void ABaseCharacter::MoveRight(const float Val)
{
	if (!CanMove) return;
	IsMovingRight = !FMath::IsNearlyZero(Val);
	AddMovementInput(GetActorRightVector(), Val);
}

void ABaseCharacter::LookUp(const float Val)
{
	AddControllerPitchInput(Val);
}

auto ABaseCharacter::LookRight(float Val) -> void
{
	AddControllerYawInput(Val);;
}

void ABaseCharacter::GetHit()
{
}

void ABaseCharacter::Attack()
{
}

void ABaseCharacter::StartSprint()
{
	IsSprint = true;
}

void ABaseCharacter::EndSprint()
{
	IsSprint = false;
}

void ABaseCharacter::OnImpacted()
{
	ImpactInfo.SourceLocation = GetActorLocation();
	ImpactInfo.DesiredDirection = -GetActorForwardVector().GetSafeNormal();
	ImpactInfo.CurrentVelocity = ImpactInfo.InitVelocity;
	ImpactInfo.DesiredLocation = ImpactInfo.SourceLocation + ImpactInfo.DesiredDirection * MathUtils::GetDistance(
		-ImpactInfo.Accel, ImpactInfo.InitVelocity, ImpactInfo.InitVelocity / ImpactInfo.Accel);

	GetWorld()->GetTimerManager().SetTimer(ImpactedTimer, this, &ABaseCharacter::ProcessImpactedLocation,
	                                       ImpactInfo.DeltaTime, true);

	if (HitAnim_Light)
		PlayAnimMontage(HitAnim_Light);
}

void ABaseCharacter::ProcessImpactedLocation()
{
	const float DeltaX = MathUtils::GetDeltaX(ImpactInfo.CurrentVelocity,
                       	                                          MathUtils::GetV0(ImpactInfo.CurrentVelocity,
	                                                           -ImpactInfo.Accel,
	                                                           ImpactInfo.DeltaTime), ImpactInfo.DeltaTime);

	SetActorLocation(GetActorLocation() + ImpactInfo.DesiredDirection * DeltaX);

	ImpactInfo.CurrentVelocity -= ImpactInfo.Accel * ImpactInfo.DeltaTime;
	if (ImpactInfo.CurrentVelocity <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(ImpactedTimer);
	}
}
