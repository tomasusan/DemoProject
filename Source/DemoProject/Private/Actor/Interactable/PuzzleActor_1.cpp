// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Interactable/PuzzleActor_1.h"

#include "Components/TextRenderComponent.h"

DEFINE_LOG_CATEGORY_STATIC(APuzzleActor_1Log, All, All);

APuzzleActor_1::APuzzleActor_1()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	Mesh_1 = CreateDefaultSubobject<UStaticMeshComponent>("Mesh_1");
	Mesh_1->SetupAttachment(GetRootComponent());

	Mesh_2 = CreateDefaultSubobject<UStaticMeshComponent>("Mesh_2");
	Mesh_2->SetupAttachment(GetRootComponent());

	TextComponent = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
	TextComponent->SetupAttachment(GetRootComponent());
}

void APuzzleActor_1::Interact_Implementation(AActor* InstigatorActor)
{
	Super::Interact_Implementation(InstigatorActor);
	UE_LOG(APuzzleActor_1Log, Warning, TEXT("Trigered!"));
	if (!ShowMesh_2)
	{
		SwitchShowMesh_2();
		UE_LOG(APuzzleActor_1Log, Warning, TEXT("Now Broadcast"));
		TriggeredDelegate.Broadcast(GetIndex());
	}
}

void APuzzleActor_1::BeginPlay()
{
	Super::BeginPlay();

	Mesh_2->SetVisibility(false);
}

void APuzzleActor_1::SetIndex(const int32 NewIndex)
{
	Super::SetIndex(NewIndex);
	TextComponent->SetText(FText::FromString(FString::FromInt(NewIndex)));
}

void APuzzleActor_1::ResetState()
{
	UE_LOG(APuzzleActor_1Log, Warning, TEXT("%d: Call Reset"), GetIndex());
	Mesh_2->SetVisibility(false);
	ShowMesh_2 = false;
}

void APuzzleActor_1::SwitchShowMesh_2()
{
	UE_LOG(APuzzleActor_1Log, Warning, TEXT("%d: Call Mesh Switch"), GetIndex());
	if (ShowMesh_2)
	{
		return;
		Mesh_2->SetVisibility(false);
		ShowMesh_2 = false;
	}
	else
	{
		Mesh_2->SetVisibility(true);
		ShowMesh_2 = true;
	}
}
