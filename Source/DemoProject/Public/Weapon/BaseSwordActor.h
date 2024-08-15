// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BaseWeaponActor.h"
#include "BaseSwordActor.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API ABaseSwordActor : public ABaseWeaponActor
{
	GENERATED_BODY()
public:
	virtual void ApplyAttack() override;
	virtual void EndAttack() override;
};
