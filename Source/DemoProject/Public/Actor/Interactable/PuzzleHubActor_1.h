// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleHubActor_1.generated.h"

class UDataTable;
DECLARE_MULTICAST_DELEGATE(FResetAllSignature);

UCLASS()
class DEMOPROJECT_API APuzzleHubActor_1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleHubActor_1();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="PuzzleActor")
	TSubclassOf<AActor> PuzzleActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PuzzleActor")
	TArray<FTransform> SpawnLocations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PuzzleActor")
	FString Order;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PuzzleInfo")
	UDataTable* PuzzleInfoTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PuzzleInfo")
	FName PuzzleID;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void OnActorTriggered(int32 ActorIndex);

private:
	void SpawnPuzzleActor();

	FString CurrentTriggerOrder = "";
	bool CheckOrder(FString ExpectedOrder, FString CurrentOrder, bool& Finished);

	FResetAllSignature ResetAllDelegate;
};
