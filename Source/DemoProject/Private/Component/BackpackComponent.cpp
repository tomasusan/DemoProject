// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/BackpackComponent.h"

#include "DemoProject/ItemInfoUtils.h"

DEFINE_LOG_CATEGORY_STATIC(BackpackComponentLog, All, All);

// Sets default values for this component's properties
UBackpackComponent::UBackpackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UBackpackComponent::BeginPlay()
{
	Super::BeginPlay();

	LoadToBackpack(Items_ID);
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

	if (TypeTable)
	{
		const auto ItemType = FItemInfoUtils::GetItemType(TypeTable, NewItem.ID);
		const auto Num = GetItemNums(NewItem);
		OnPickItemDelegate.Broadcast(ItemType, Num);
	}
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

int32 UBackpackComponent::GetItemNums(const FItemInBackpackState& CheckItem)
{
	int32 Ret = 0;
	for (const auto Item : Items)
	{
		if (Item.ID == CheckItem.ID)
		{
			Ret += Item.CurrentNum;
		}
	}

	return Ret;
}

int32 UBackpackComponent::GetItemNums(const FString& ID)
{
	int32 Ret = 0;
	for (const auto Item : Items)
	{
		if (Item.ID == ID)
		{
			Ret += Item.CurrentNum;
		}
	}

	return Ret;
}

int32 UBackpackComponent::GetItemNums(const ETagType Type)
{
	int32 Ret = 0;
	for (const auto Item : Items)
	{
		if (FItemInfoUtils::GetItemType(TypeTable, Item.ID) == Type)
		{
			Ret += Item.CurrentNum;
		}
	}

	return Ret;
}
