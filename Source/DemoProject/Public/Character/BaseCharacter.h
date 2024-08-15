// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DemoProject/CharacterCoreTypes.h"
#include "BaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class DEMOPROJECT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& ObjInit);

	UFUNCTION(BlueprintCallable)
	float GetMovementDirection() const;

	UFUNCTION(BlueprintCallable)
	bool IsMoving() const;

	// UFUNCTION(BlueprintCallable)
	// bool IsFalling() const;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UCameraComponent* CameraComponent;

	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveForward(const float Val);
	virtual void MoveRight(const float Val);
	virtual void LookUp(const float Val);
	virtual void LookRight(const float Val);
	virtual void GetHit();

	void SetCanMove(const bool NewState) {CanMove = NewState;}
	void SetIsSprint(const bool NewState) {IsSprint = NewState;}
	bool GetCanMove() const{return CanMove;}

	bool IsSprinting() const {return IsSprint;}
	
	void OnImpacted();

	virtual void Attack();
	virtual void StartSprint();
	virtual void EndSprint();

	bool IsMovingForward = false;
	bool IsMovingRight = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Impacted");
	FImpactInfo ImpactInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Anim")
	UAnimMontage* HitAnim_Light;

private:
	void ProcessImpactedLocation();
	

	bool IsSprint = false;
	bool CanMove = true;
	FTimerHandle ImpactedTimer;
};
