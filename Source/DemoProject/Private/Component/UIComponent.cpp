// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UIComponent.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI/BackpackMainWidget.h"

// Sets default values for this component's properties
UUIComponent::UUIComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UUIComponent::BeginPlay()
{
	Super::BeginPlay();

	InitUI();
}

void UUIComponent::SwitchBackpack()
{
	if (MainWidget)
	{
		MainWidget->SwitchBackpack();
	}
}

void UUIComponent::ShowDetectBar() const
{
	MainWidget->ShowDetectActorBar();
}

void UUIComponent::HideDetectBar() const
{
	MainWidget->HideDetectActorBar();
}

void UUIComponent::InitUI()
{
	MainWidget = CreateWidget<UBackpackMainWidget>(GetWorld()->GetFirstPlayerController(), MainWidgetClass);
	MainWidget->AddToViewport();
}
