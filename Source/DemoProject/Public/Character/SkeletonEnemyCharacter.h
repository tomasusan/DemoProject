// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseEnemyCharacter.h"
#include "SkeletonEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API ASkeletonEnemyCharacter : public ABaseEnemyCharacter
{
	GENERATED_BODY()

public:
	ASkeletonEnemyCharacter();

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> Helmet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> Torso;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> ShoulderArmor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> Shoes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> Helmet2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> Pants;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> PantsArmor;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armor")
	TArray<USkeletalMesh*> Gloves;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Modular Armmor")
	TArray<USkeletalMesh*> ArmArmor;

	virtual void Attack() override;
	virtual void Skill_1() override;
	virtual void Skill_2() override;
	virtual void Die() override;

	virtual void GetHit() override;
	virtual void RandomAttack() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* HelmetsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* TorsoMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* ShoulderArmorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* ShoesMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* Helmets2Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* PantsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* GlovesMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* ArmArmorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* ArmBoneMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* HandBoneMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* ThighBoneMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* FootBoneMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USkeletalMeshComponent* RibsBoneMesh;

private:
	void SetArmor();
	virtual void InitAnimNotify() override;
	void InitLeaderSkeletonComponent();
};
