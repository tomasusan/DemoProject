// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoProject/ItemCoreTypes.h"
#include "InteractComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEMOPROJECT_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(AActor* OtherActor);

	void LoadItemInfo(const FItemBasicInfo& Info) { CurrentItemInfo = Info; }

	bool NowDetect() const { return CurrentDetectedActor != nullptr; }
	AActor* GetDetectedActor() const {return CurrentDetectedActor;}

private:
	UPROPERTY()
	AActor* CurrentDetectedActor;

	bool DetectActor = false;
	FItemBasicInfo CurrentItemInfo;
};
