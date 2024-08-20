#pragma once

#include "DemoProject/ItemCoreTypes.h"

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
};