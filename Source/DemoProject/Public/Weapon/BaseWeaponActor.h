// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeaponActor.generated.h"

class ABaseCharacter;

UCLASS()
class DEMOPROJECT_API ABaseWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeaponActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UStaticMeshComponent* WeaponMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void ApplyAttack();

	UFUNCTION(BlueprintCallable)
	virtual void EndAttack();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Damage")
	FName DamageStartSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Damage")
	FName DamageEndSocketName;

	TSet<ABaseCharacter*> HitCharacterPool;

};
