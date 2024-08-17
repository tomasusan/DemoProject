// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/BackpackComponent.h"

// Sets default values for this component's properties
UBackpackComponent::UBackpackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBackpackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UBackpackComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FItemInBackpackState> UBackpackComponent::GetItemsToBackpack() const
{
	TArray<FItemInBackpackState> Ret;
	for(const auto Item:Items_ID)
	{
		if(Datatable)
		{
			const auto FromTableInfo = Datatable->FindRow<FItemBasicInfo>(Item, "");
			if(FromTableInfo)
			{
				Ret.Add(GetInBackpackState(*FromTableInfo));
			}
		}
	}
	return Ret;
}

FItemInBackpackState UBackpackComponent::GetInBackpackState(const FItemBasicInfo& Info)
{
	FItemInBackpackState Ret;
	Ret.ID = Info.ID;
	Ret.Icon = Info.Icon;
	Ret.Stackable = Info.Stackable;
	Ret.CurrentNum = 1;
	Ret.ItemName = Info.ItemName;
	Ret.ItemType = Info.ItemType;
	Ret.MaxStackNum = Info.MaxStackNum;

	return Ret;
}
