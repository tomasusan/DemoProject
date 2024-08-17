// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BackpackCellWidget.h"

void UBackpackCellWidget::UpdateCell(FItemInBackpackState Info, bool MakeDefault)
{
	if (MakeDefault)
	{
		Icon = DefaultIcon;
	}
	else
	{
		Icon = Info.Icon;
	}

	ItemName = Info.ItemName.ToString();
	ItemNum = FString::FromInt(Info.CurrentNum);
	ID = Info.ID;
}
