// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Interactable/BasePickableActor.h"

#include "PlayerCharacter.h"
#include "Components/TextRenderComponent.h"
#include "Engine/DataTable.h"

DEFINE_LOG_CATEGORY_STATIC(PickableActorLog, All, All);

ABasePickableActor::ABasePickableActor()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
	ActorMesh->SetupAttachment(GetRootComponent());

	TextComponent = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
	TextComponent->SetupAttachment(GetRootComponent());
}

void ABasePickableActor::BeginPlay()
{
	Super::BeginPlay();

	LoadInfo(ItemID);
	TextComponent->SetText(FText::FromString(BasicInfo.ID));
}

void ABasePickableActor::Interact_Implementation(AActor* InstigatorActor)
{
	Super::Interact_Implementation(InstigatorActor);

	if(const auto Character = Cast<APlayerCharacter>(InstigatorActor))
	{
		Character->BackpackAdd(BasicInfo);
		//UE_LOG(PickableActorLog, Warning, TEXT("Triggered!"));
	}
}

void ABasePickableActor::LoadInfo(const FName ID)
{
	if(const auto TableInfo = DataTable->FindRow<FItemBasicInfo>(ID, ""))
	{
		BasicInfo = *TableInfo;
	}
}
