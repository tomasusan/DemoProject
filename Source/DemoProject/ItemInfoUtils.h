#pragma once

#include "DemoProject/ItemCoreTypes.h"
#include "DemoProject/TagCoreTypes.h"

class FItemInfoUtils
{
public:
	static FItemInBackpackState ConvertInBackpackState(FItemBasicInfo Info)
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

	static ETagType GetItemType(const UDataTable* Table, const FString& ItemID)
	{
		const FName RowName = FName(ItemID);
		if (const auto TableInfo = Table->FindRow<FItemID2TagType>(RowName, ""))
		{
			return TableInfo->Type;
		}
		else
		{
			return ETagType::End;
		}
	}
};
