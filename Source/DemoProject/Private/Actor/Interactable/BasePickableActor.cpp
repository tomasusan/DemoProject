// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Interactable/BasePickableActor.h"
#include "Engine/DataTable.h"

ABasePickableActor::ABasePickableActor()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
	ActorMesh->SetupAttachment(GetRootComponent());
}

void ABasePickableActor::BeginPlay()
{
	Super::BeginPlay();

	LoadInfo(ItemID);
}

void ABasePickableActor::Interact_Implementation(AActor* InstigatorActor)
{
	Super::Interact_Implementation(InstigatorActor);
}

void ABasePickableActor::LoadInfo(const FName ID)
{
	if(const auto TableInfo = DataTable->FindRow<FItemBasicInfo>(ID, ""))
	{
		BasicInfo = *TableInfo;
	}
}
