// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "BaseEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API ABaseEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	bool GetInAnim() const {return InAnim;}
	void SetInAnim(bool NewState) {InAnim = NewState;}
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	UAnimMontage* AttackAnim_1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	UAnimMontage* AttackAnim_2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	UAnimMontage* DeathAnim;;
	
	virtual void OnEntryAnim();
	virtual void OnOutAnim();

	virtual void Skill_1();
	virtual void Skill_2();
	virtual void Die();

private:
	bool InAnim = false;
};
