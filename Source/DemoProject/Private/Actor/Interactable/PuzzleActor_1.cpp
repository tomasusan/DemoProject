// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Interactable/PuzzleActor_1.h"

#include "Components/TextRenderComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

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
	if (!ShowMesh_2)
	{
		SwitchShowMesh_2();
		TriggeredDelegate.Broadcast(GetIndex());
	}
}

void APuzzleActor_1::BeginPlay()
{
	Super::BeginPlay();

	Mesh_2->SetVisibility(false);

	DMI_1 = Mesh_1->CreateAndSetMaterialInstanceDynamic(0);
	DMI_2 = Mesh_2->CreateAndSetMaterialInstanceDynamic(0);
}

void APuzzleActor_1::SetIndex(const int32 NewIndex)
{
	Super::SetIndex(NewIndex);
	TextComponent->SetText(FText::FromString(FString::FromInt(NewIndex)));
}

void APuzzleActor_1::ResetState()
{
	Mesh_2->SetVisibility(false);
	ShowMesh_2 = false;
}

void APuzzleActor_1::CallDissolve()
{
	GetWorld()->GetTimerManager().SetTimer(MeshDissolveHandler, this, &APuzzleActor_1::OnMeshDissolve,
	                                       DeltaDissolveTime, true);
}

void APuzzleActor_1::SwitchShowMesh_2()
{
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

void APuzzleActor_1::OnMeshDissolve()
{
	const float NewDissolveVal = GetDissolveValue(MeshCurrentDissolveTime);
	if (GetIndex() == 1)
	{
		UE_LOG(APuzzleActor_1Log, Warning, TEXT("Get Value: %f"), NewDissolveVal);
	}

	DMI_1->SetScalarParameterValue("Dissolve", NewDissolveVal);
	DMI_2->SetScalarParameterValue("Dissolve", NewDissolveVal);

	MeshCurrentDissolve = NewDissolveVal;
	MeshCurrentDissolveTime += DeltaDissolveTime;

	if (MeshCurrentDissolve <= 0.0001)
	{
		GetWorld()->GetTimerManager().ClearTimer(MeshDissolveHandler);
		Mesh_1->SetVisibility(false);
		Mesh_2->SetVisibility(false);
		if (GetIndex() == 1)
		{
			UE_LOG(APuzzleActor_1Log, Warning, TEXT("End: Dissolve:%f / %f"), MeshCurrentDissolve, DissolveTime);
		}
		SetLifeSpan(.1);
	}
}

float APuzzleActor_1::GetDissolveVelocity(const float Time) const
{
	if (Time <= DissolveTime / 2)
	{
		float Ret = -4.8 / DissolveTime * DissolveTime * Time;
		if (GetIndex() == 1)
		{
			UE_LOG(APuzzleActor_1Log, Warning, TEXT("Time: %f / %f"), MeshCurrentDissolveTime, Ret);
		}
		return -4.8 / DissolveTime * DissolveTime * Time;
	}
	else
	{
		float Ret = 4.8 / DissolveTime * DissolveTime * Time - 4.8 / DissolveTime;
		if (GetIndex() == 1)
		{
			UE_LOG(APuzzleActor_1Log, Warning, TEXT("Time: %f / %f"), MeshCurrentDissolveTime, Ret);
		}
		return Ret;
	}
}

float APuzzleActor_1::GetDissolveValue(const float Time) const
{
	if (Time <= DissolveTime / 2)
	{
		float Ret = -2.4 / (DissolveTime * DissolveTime) * Time + 1.2;
		if (GetIndex() == 1)
		{
			UE_LOG(APuzzleActor_1Log, Warning, TEXT("-2.4 / %f * %f * %f + 1.2 = %f"), DissolveTime, DissolveTime, Time,
			       Ret);
		}
		//UE_LOG(APuzzleActor_1Log, Warning, TEXT("%f: %f / %f"),DissolveTime, MeshCurrentDissolveTime, Ret);
		return -2.4 / (DissolveTime * DissolveTime) * Time + 1.2;
	}
	else
	{
		float Ret = 2.4 / (DissolveTime * DissolveTime) * ((Time - DissolveTime) * (Time - DissolveTime));
		if (GetIndex() == 1)
		{
			UE_LOG(APuzzleActor_1Log, Warning, TEXT("%f: %f / %f"), DissolveTime, MeshCurrentDissolveTime, Ret);
		}
		return 2.4 / (DissolveTime * DissolveTime) * ((Time - DissolveTime) * (Time - DissolveTime));
	}
}
