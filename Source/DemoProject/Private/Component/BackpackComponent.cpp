// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/BackpackComponent.h"

#include "DemoProject/ItemInfoUtils.h"

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

	LoadToBackpack(Items_ID);
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
	return Items;
}

void UBackpackComponent::BackpackAdd(const FItemInBackpackState& NewItem)
{
	for (auto Item : Items)
	{
		if (Item.ID == NewItem.ID)
		{
			if (Item.Stackable && Item.CurrentNum < Item.MaxStackNum)
			{
				Item.CurrentNum++;
				return;
			}
			else
			{
				Items.Add(NewItem);
				return;
			}
		}
	}
	Items.Add(NewItem);
}

void UBackpackComponent::LoadToBackpack(TArray<FName> NewItems)
{
	for (const auto Item : NewItems)
	{
		if (const auto TableInfo = Datatable->FindRow<FItemBasicInfo>(Item, ""))
		{
			const auto InBackpackInfo = FItemInfoUtils::ConvertInBackpackState(*TableInfo);
			BackpackAdd(InBackpackInfo);
		}
	}
}
