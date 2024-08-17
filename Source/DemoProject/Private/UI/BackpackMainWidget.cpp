// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BackpackMainWidget.h"

#include "PlayerCharacter.h"
#include "UI/BackpackCellWidget.h"

void UBackpackMainWidget::InitCell()
{
	for (int i = 0; i < CellNum; i++)
	{
		const auto Cell = CreateWidget<UBackpackCellWidget>(GetWorld(), CellClass, "BackpackCell");
		Cells.Add(Cell);
	}
}

void UBackpackMainWidget::GetRowColumn(int32 Index, int32& Row, int32& Column)
{
	Row = Index / RowNum;
	Column = Index % RowNum;
}

void UBackpackMainWidget::SetCells(const TArray<UBackpackCellWidget*>& SetCells)
{
	Cells = SetCells;
}

void UBackpackMainWidget::AddCells(UBackpackCellWidget* AddCells)
{
	Cells.Add(AddCells);
}

void UBackpackMainWidget::ClearCells()
{
	Cells.Empty();
}

void UBackpackMainWidget::UpdateBackpack()
{
	const auto Items = GetItems();
	for (int i = 0; i < CellNum; i++)
	{
		if (Items.IsValidIndex(i))
		{
			Cells[i]->UpdateCell(Items[i]);
		}
		else
		{
			Cells[i]->UpdateCell(FItemInBackpackState{}, true);
		}
	}
}

void UBackpackMainWidget::SelectItemByType(EItemType Type)
{
	const auto Items = GetItems();
	TArray<FItemInBackpackState> SelectedItem;
	for (const auto Item : Items)
	{
		if(Item.ItemType == Type)
		{
			SelectedItem.Add(Item);
		}
	}
	for (int i = 0; i < CellNum; i++)
	{
		if (SelectedItem.IsValidIndex(i))
		{
			Cells[i]->UpdateCell(SelectedItem[i]);
		}
		else
		{
			Cells[i]->UpdateCell(FItemInBackpackState{}, true);
		}
	}
}

TArray<FItemInBackpackState> UBackpackMainWidget::GetItems()
{
	TArray<FItemInBackpackState> Ret;
	const auto Character = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!Character) return Ret;

	Ret = Character->GetBackpackItems();
	return Ret;
}
