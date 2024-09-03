// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/BaseTriggerActor.h"
#include "DoorTriggerActor.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API ADoorTriggerActor : public ABaseTriggerActor
{
	GENERATED_BODY()

public:
	ADoorTriggerActor();

	virtual void Triggered_Implementation() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Out")
	float ExpectHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Out")
	float UpTime;
	
	void OnMove();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UStaticMeshComponent* StaticMesh;

	
private:
	float CurrentOutTime = 0;
	FVector InitLocation;
	FVector GetExpectLocation(float Time) const;
	FTimerHandle OnMoveTimer;
};
