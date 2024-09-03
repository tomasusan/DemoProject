// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/InteractComponent.h"

#include "Actor/Interactable/BaseInteractableActor.h"
#include "Component/UIComponent.h"

DEFINE_LOG_CATEGORY_STATIC(ComponentLog, All, All);

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UInteractComponent::OnOverlapBegin(AActor* OtherActor)
{
	CurrentDetectedActor = OtherActor;
	DetectActor = true;
	if (!CurrentDetectedActor->IsA<ABaseInteractableActor>())
	{
		return;
	}

	//UE_LOG(ComponentLog, Warning, TEXT("Detect: %s"), *OtherActor->GetName());

	const auto UIComponent = GetOwner()->FindComponentByClass<UUIComponent>();
	UIComponent->ShowDetectBar();
}

void UInteractComponent::OnOverlapEnd(AActor* OtherActor)
{
	CurrentDetectedActor = nullptr;
	DetectActor = false;

	//UE_LOG(ComponentLog, Warning, TEXT("No Detect"));

	const auto UIComponent = GetOwner()->FindComponentByClass<UUIComponent>();
	UIComponent->HideDetectBar();
}
