// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/InteractInterface.h"
#include "BaseInteractableActor.generated.h"

UCLASS()
class DEMOPROJECT_API ABaseInteractableActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseInteractableActor();

	virtual void SetIndex(const int32 NewIndex) { HubIndex = NewIndex; }
	virtual int32 GetIndex() const { return HubIndex; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int32 HubIndex = -1;
};
