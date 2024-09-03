// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/DoorTriggerActor.h"

DEFINE_LOG_CATEGORY_STATIC(DoorLog, All, All);

ADoorTriggerActor::ADoorTriggerActor()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(SceneComponent);
}

void ADoorTriggerActor::Triggered_Implementation()
{
	
	//StaticMesh->SetVisibility(false);
	InitLocation = GetActorLocation();
	CurrentOutTime = 0;
	GetWorld()->GetTimerManager().SetTimer(OnMoveTimer, this, &ADoorTriggerActor::OnMove, 0.01, true);
}

void ADoorTriggerActor::OnMove()
{
	const auto Location = GetExpectLocation(CurrentOutTime);
	SetActorLocation(Location);
	CurrentOutTime += 0.01;
	if (Location.Z >= ExpectHeight)
	{
		GetWorld()->GetTimerManager().ClearTimer(OnMoveTimer);
	}
}

FVector ADoorTriggerActor::GetExpectLocation(const float Time) const
{
	const float Height = ExpectHeight / (UpTime * UpTime) * (Time * Time);
	FVector Ret = InitLocation;
	Ret.Z += Height;
	return Ret;
}
