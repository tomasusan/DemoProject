// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "DemoProject/CharacterCoreTypes.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */

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

	UFUNCTION(BlueprintCallable)
	void SetWantCombo() { ComboInfo.WantCombo = false; }

	UFUNCTION(BlueprintCallable)
	void SetOutAnim();

	// UFUNCTION(BlueprintCallable)
	// void SetOutAnim();

	UFUNCTION(BlueprintCallable)
	FComboInfo GetComboInfo() const { return ComboInfo; }

public:
	virtual void Attack() override;
	virtual void ProAttack();
	virtual void StartSprint() override;
	virtual void EndSprint() override;
	virtual void MoveForward(const float Val) override;
	virtual void MoveRight(const float Val) override;

	void OpenCombo();
	void CloseCombo();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


private:
	void InitAnimation();
	void SetEntryAnim();
	void OnStopDetectInput();
	void WantCombo2();
	void WantCombo3();
	void OnStartAvoid();
	void OnEndVoid();
	void OnCheckShiftDown();
	FComboInfo ComboInfo;

	bool CanAttack = true;
	bool ShiftDown = false;
	EDesireDirection DesireDirection = EDesireDirection::Front;

	void ProcessDesireDirection();

	FTimerHandle SprintTimer;

	
};
