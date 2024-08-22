// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Interactable/PuzzleHubActor_1.h"

#include "Actor/Interactable/BaseInteractableActor.h"
#include "Engine/DataTable.h"
#include "Actor/Interactable/PuzzleActor_1.h"
#include "DemoProject/PuzzleCoreTypes.h"

DEFINE_LOG_CATEGORY_STATIC(HubActorLog, All, All);

// Sets default values
APuzzleHubActor_1::APuzzleHubActor_1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APuzzleHubActor_1::BeginPlay()
{
	Super::BeginPlay();
	if (const auto Info = PuzzleInfoTable->FindRow<FPuzzleInfo_1>(PuzzleID, ""))
	{
		SpawnLocations = Info->Locations;
		Order = Info->Order;
		SpawnPuzzleActor();
	}
}

void APuzzleHubActor_1::OnActorTriggered(const int32 ActorIndex)
{
	UE_LOG(HubActorLog, Warning, TEXT("Recieve SubActor Trigered"));
	CurrentTriggerOrder.Append(FString::FromInt(ActorIndex));
	UE_LOG(HubActorLog, Warning, TEXT("%s"), *CurrentTriggerOrder);
	if (CurrentTriggerOrder.Len() == 1) return;
	if (bool Finished; !CheckOrder(Order, CurrentTriggerOrder, Finished))
	{
		UE_LOG(HubActorLog, Warning, TEXT("Wrong Order"));
		CurrentTriggerOrder.Empty();
		ResetAllDelegate.Broadcast();
	}
	else if (Finished)
	{
		UE_LOG(HubActorLog, Warning, TEXT("Right Order"));
	}
}

void APuzzleHubActor_1::SpawnPuzzleActor()
{
	int32 Index = 0;
	for (auto Transform : SpawnLocations)
	{
		if (const auto Actor = GetWorld()->SpawnActor<APuzzleActor_1>(PuzzleActorClass))
		{
			Actor->SetActorTransform(Transform);
			Actor->SetOwner(this);
			Actor->SetIndex(Index + 1);

			Actor->TriggeredDelegate.AddUObject(this, &APuzzleHubActor_1::OnActorTriggered);
			ResetAllDelegate.AddUObject(Actor, &APuzzleActor_1::ResetState);
		}
		Index++;
	}
}


bool APuzzleHubActor_1::CheckOrder(FString ExpectedOrder, FString CurrentOrder, bool& Finished)
{
	Finished = false;
	if (ExpectedOrder.Equals(CurrentOrder))
	{
		Finished = true;
		return true;
	}

	int32 Index = 0;
	for (const auto Member : CurrentOrder)
	{
		if (Member != ExpectedOrder[Index])
		{
			return false;
		}
		Index++;
	}

	return true;
}
