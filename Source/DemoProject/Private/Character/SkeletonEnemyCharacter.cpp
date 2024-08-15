// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SkeletonEnemyCharacter.h"

#include "Animation/EntryAnimNotify.h"
#include "Animation/OutAnimNotify.h"
#include "DemoProject/AnimUtils.h"

ASkeletonEnemyCharacter::ASkeletonEnemyCharacter()
{
	InitLeaderSkeletonComponent();
	InitAnimNotify();
}

void ASkeletonEnemyCharacter::Attack()
{
	Super::Attack();

	if (AttackAnim_1)
		PlayAnimMontage(AttackAnim_1);
}

void ASkeletonEnemyCharacter::Skill_1()
{
	Super::Skill_1();
}

void ASkeletonEnemyCharacter::Skill_2()
{
	Super::Skill_2();
}

void ASkeletonEnemyCharacter::Die()
{
	Super::Die();
}

void ASkeletonEnemyCharacter::GetHit()
{
	Super::GetHit();
	OnImpacted();
	PlayAnimMontage(HitAnim_Light);
}

void ASkeletonEnemyCharacter::RandomAttack()
{
	if (!GeneratePossibleAttack()) return;

	switch (FMath::RandRange(1, 2))
	{
	case 1:
		PlayAnimMontage(AttackAnim_1);
		break;
	case 2:
		PlayAnimMontage(AttackAnim_2);
		break;
	default:
		break;
	}
}

void ASkeletonEnemyCharacter::SetArmor()
{
}

void ASkeletonEnemyCharacter::InitAnimNotify()
{
	UEntryAnimNotify* EntryAnimNotify;
	UOutAnimNotify* OutAnimNotify;
	if (AttackAnim_1)
	{
		EntryAnimNotify = AnimUtils::FindNotifyByClass<UEntryAnimNotify>(AttackAnim_1);
		OutAnimNotify = AnimUtils::FindNotifyByClass<UOutAnimNotify>(AttackAnim_1);
		if (EntryAnimNotify && OutAnimNotify)
		{
			EntryAnimNotify->OnNotified.AddUObject(this, &ASkeletonEnemyCharacter::OnEntryAnim);
			OutAnimNotify->OnNotified.AddUObject(this, &ASkeletonEnemyCharacter::OnOutAnim);
		}
	}

	if (AttackAnim_2)
	{
		EntryAnimNotify = AnimUtils::FindNotifyByClass<UEntryAnimNotify>(AttackAnim_2);
		OutAnimNotify = AnimUtils::FindNotifyByClass<UOutAnimNotify>(AttackAnim_2);
		if (EntryAnimNotify && OutAnimNotify)
		{
			EntryAnimNotify->OnNotified.AddUObject(this, &ASkeletonEnemyCharacter::OnEntryAnim);
			OutAnimNotify->OnNotified.AddUObject(this, &ASkeletonEnemyCharacter::OnOutAnim);
		}
	}
}

void ASkeletonEnemyCharacter::InitLeaderSkeletonComponent()
{
	HelmetsMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HelmetMesh");
	HelmetsMesh->SetupAttachment(GetMesh());

	TorsoMesh = CreateDefaultSubobject<USkeletalMeshComponent>("TorsoMesh");
	TorsoMesh->SetupAttachment(GetMesh());

	ShoulderArmorMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ShoulderArmorMesh");
	ShoulderArmorMesh->SetupAttachment(GetMesh());

	ShoesMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ShoesMesh");
	ShoesMesh->SetupAttachment(GetMesh());

	Helmets2Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Helmet2Mesh");
	Helmets2Mesh->SetupAttachment(GetMesh());

	PantsMesh = CreateDefaultSubobject<USkeletalMeshComponent>("PantsMesh");
	PantsMesh->SetupAttachment(GetMesh());

	GlovesMesh = CreateDefaultSubobject<USkeletalMeshComponent>("GlovesMesh");
	GlovesMesh->SetupAttachment(GetMesh());

	ArmArmorMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ArmArmorMesh");
	ArmArmorMesh->SetupAttachment(GetMesh());

	ArmBoneMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ArmMesh");
	ArmBoneMesh->SetupAttachment(GetMesh());

	HandBoneMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandBoneMesh");
	HandBoneMesh->SetupAttachment(GetMesh());

	ThighBoneMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ThighBoneMesh");
	ThighBoneMesh->SetupAttachment(GetMesh());

	FootBoneMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FootBoneMesh");
	FootBoneMesh->SetupAttachment(GetMesh());

	RibsBoneMesh = CreateDefaultSubobject<USkeletalMeshComponent>("RibsBoneMesh");
	RibsBoneMesh->SetupAttachment(GetMesh());

	HelmetsMesh->SetLeaderPoseComponent(GetMesh());
	TorsoMesh->SetLeaderPoseComponent(GetMesh());
	ShoulderArmorMesh->SetLeaderPoseComponent(GetMesh());
	ShoesMesh->SetLeaderPoseComponent(GetMesh());
	Helmets2Mesh->SetLeaderPoseComponent(GetMesh());
	PantsMesh->SetLeaderPoseComponent(GetMesh());
	GlovesMesh->SetLeaderPoseComponent(GetMesh());
	ArmArmorMesh->SetLeaderPoseComponent(GetMesh());
	ArmBoneMesh->SetLeaderPoseComponent(GetMesh());
	HandBoneMesh->SetLeaderPoseComponent(GetMesh());
	ThighBoneMesh->SetLeaderPoseComponent(GetMesh());
	FootBoneMesh->SetLeaderPoseComponent(GetMesh());
	RibsBoneMesh->SetLeaderPoseComponent(GetMesh());
}
