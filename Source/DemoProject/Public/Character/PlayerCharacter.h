// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Component/BackpackComponent.h"
#include "DemoProject/CharacterCoreTypes.h"
#include "DemoProject/ItemCoreTypes.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */

class UBackpackComponent;
class UWeaponComponent;
class UBoxComponent;

UENUM()
enum EDesireDirection:uint8
{
	Left = 0,
	Right = 1,
	Front = 2,
	Back = 3
};

UCLASS()
class DEMOPROJECT_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter(const FObjectInitializer& ObjInit);

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	UAnimMontage* ProAttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	TArray<UAnimMontage*> AvoidAnims;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	FName RightHandWeaponSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	FName LeftHandWeaponSocketName;

	UFUNCTION(BlueprintCallable)
	void SetWantCombo() { ComboInfo.WantCombo = false; }

	UFUNCTION(BlueprintCallable)
	void SetOutAnim();

	UFUNCTION(BlueprintCallable)
	void AddCombo();

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentCombo() const { return ComboInfo.CurrentInCombo; }

	// UFUNCTION(BlueprintCallable)
	// void SetOutAnim();

	UFUNCTION(BlueprintCallable)
	FComboInfo GetComboInfo() const { return ComboInfo; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UWeaponComponent* WeaponComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UBackpackComponent* BackpackComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UBoxComponent* BoxCollision;

public:
	virtual void Attack() override;
	virtual void ProAttack();
	virtual void StartSprint() override;
	virtual void EndSprint() override;
	virtual void MoveForward(const float Val) override;
	virtual void MoveRight(const float Val) override;

	TArray<FItemInBackpackState> GetBackpackItems() const { return BackpackComponent->GetItemsToBackpack(); }

	void OpenCombo();
	void CloseCombo();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void LoadAttackNotifyState();

	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(AActor* OtherActor);

private:
	void InitAnimation();
	void SetEntryAnim();
	void OnStopDetectInput();
	void WantCombo2();
	void WantCombo3();
	void OnStartAvoid();
	void OnEndVoid();
	void OnCheckShiftDown();
	void Interact();
	void ProcessDesireDirection();
	void BackpackAdd();

	template <typename T>
	T* SpawnWeapon(TSubclassOf<T> WeaponClass, FName SocketName);

	bool CanAttack = true;
	bool ShiftDown = false;
	bool DetectActor = false;
	
	EDesireDirection DesireDirection = EDesireDirection::Front;
	FComboInfo ComboInfo;
	FTimerHandle SprintTimer;
	
	UPROPERTY()
	AActor* CurrentDetectedActor;
};
