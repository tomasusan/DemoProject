// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoProject/TagCoreTypes.h"
#include "MissionTagComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOPROJECT_API UMissionTagComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMissionTagComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:
	TArray<FCommonTagCountCheckEventInfo> AmountCheckEvents;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<ETagType, int32> TagSequence;
	
};
