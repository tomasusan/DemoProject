#pragma once
#include "Engine/DataTable.h"
#include "ItemCoreTypes.generated.h"

UENUM(BlueprintType)
enum class EItemType: uint8
{
	Prop,
	Weapon,
	Armour,
	None
};

USTRUCT(BlueprintType)
struct FItemBasicInfo:public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	FString ID = "Invalid ID";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	FName ItemName = "Invalid Name";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	UTexture2D* Icon = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	EItemType ItemType = EItemType::None;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	bool Stackable = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	int32 MaxStackNum = -1;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	bool IsInstance = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	UStaticMesh* Mesh = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	FText Description = FText::FromString("Invalid Description");
	
};

USTRUCT(BlueprintType)
struct FItemInBackpackState
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	FString ID = "Invalid ID";
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	FName ItemName = "Invalid Name";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	UTexture2D* Icon = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	int32 CurrentNum = -1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	bool Stackable = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	int32 MaxStackNum = -1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	EItemType ItemType = EItemType::None;
};
