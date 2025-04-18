// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UBaseCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Speed");
	float MaxSpeed = 500;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Speed");
	float SprintModifier = 1.5;
	
	virtual float GetMaxSpeed() const override; 
	
};
