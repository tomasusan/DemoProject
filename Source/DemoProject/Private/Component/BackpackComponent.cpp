// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/BackpackComponent.h"

#include "DemoProject/ItemInfoUtils.h"

DEFINE_LOG_CATEGORY_STATIC(BackpackComponentLog, All, All);

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
	UE_LOG(BackpackComponentLog, Warning, TEXT("Now Calling BackpackAdd"));
	for (auto& Item : Items)
	{
		if (Item.ID == NewItem.ID)
		{
			if (Item.Stackable && Item.CurrentNum < Item.MaxStackNum)
			{
				UE_LOG(BackpackComponentLog, Warning, TEXT("Add One"));
				Item.CurrentNum++;
				return;
			}
			else
			{
				UE_LOG(BackpackComponentLog, Warning, TEXT("Add new One, One has exsisted"));
				Items.Add(NewItem);
				return;
			}
		}
	}
	UE_LOG(BackpackComponentLog, Warning, TEXT("Add total One"));
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
