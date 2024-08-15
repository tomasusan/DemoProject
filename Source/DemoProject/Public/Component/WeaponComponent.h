// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


class ABaseCharacter;
class ABaseWeaponActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOPROJECT_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	TSubclassOf<ABaseWeaponActor> RightHandWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	TSubclassOf<ABaseWeaponActor> LeftHandWeapon;

	UFUNCTION(BlueprintCallable)
	void CallAttack();

	UFUNCTION(BlueprintCallable)
	void EndAttack();
	
	UPROPERTY()
	ABaseWeaponActor* CurrentRightHandWeapon;

	UPROPERTY()
	ABaseWeaponActor* CurrentLeftHandWeapon;
};
