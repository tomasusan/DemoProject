// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoProject/ItemCoreTypes.h"
#include "DemoProject/TagCoreTypes.h"
#include "BackpackComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnPickItemSignature, ETagType, int32);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEMOPROJECT_API UBackpackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBackpackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	TArray<FItemInBackpackState> GetItemsToBackpack() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BackpackComponent")
	UDataTable* Datatable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BackpackComponent")
	UDataTable* TypeTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BackpackComponent")
	TArray<FName> Items_ID;

	void BackpackAdd(const FItemInBackpackState& NewItem);
	
	FOnPickItemSignature OnPickItemDelegate;


private:
	void LoadToBackpack(TArray<FName> NewItems);
	int32 GetItemNums(const FItemInBackpackState& CheckItem);
	int32 GetItemNums(const FString& ID);
	int32 GetItemNums(const ETagType Type);

	TArray<FItemInBackpackState> Items;
};
