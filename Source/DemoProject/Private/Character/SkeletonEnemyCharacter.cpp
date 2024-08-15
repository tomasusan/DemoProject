// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SkeletonEnemyCharacter.h"

#include "Animation/EntryAnimNotify.h"
#include "Animation/OutAnimNotify.h"
#include "DemoProject/AnimUtils.h"

ASkeletonEnemyCharacter::ASkeletonEnemyCharacter()
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

	InitAnimNotify();
}

void ASkeletonEnemyCharacter::Attack()
{
	Super::Attack();

	if(AttackAnim_1)
		PlayAnimMontage(AttackAnim_2);
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

void ASkeletonEnemyCharacter::SetArmor()
{

	
}

void ASkeletonEnemyCharacter::InitAnimNotify()
{
	auto EntryAnimNotify = AnimUtils::FindNotifyByClass<UEntryAnimNotify>(AttackAnim_1);
	auto OutAnimNotify =AnimUtils::FindNotifyByClass<UOutAnimNotify>(AttackAnim_1);

	//EntryAnimNotify->OnNotified.AddUObject(this, &ASkeletonEnemyCharacter::OnEntryAnim);
	//OutAnimNotify->OnNotified.AddUObject(this, &ASkeletonEnemyCharacter::OnOutAnim);
}
