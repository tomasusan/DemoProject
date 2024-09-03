// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/MissionTagComponent.h"

// Sets default values for this component's properties
UMissionTagComponent::UMissionTagComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	for (int i = 0; i < static_cast<int>(ETagType::End); i++)
	{
		TagSequence.Add(static_cast<ETagType>(i), 0);
	}
	// ...
}


// Called when the game starts
void UMissionTagComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}
