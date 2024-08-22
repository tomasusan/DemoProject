// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DemoProject/ItemCoreTypes.h"
#include "BackpackMainWidget.generated.h"


struct FItemInBackpackState;
class UBackpackCellWidget;
/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UBackpackMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	
	UFUNCTION(BlueprintCallable)
	void InitCell();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Cell")
	TSubclassOf<UBackpackCellWidget> CellClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Cell")
	int32 CellNum = 30;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Cell")
	int32 RowNum = 5;

	UFUNCTION(BlueprintCallable)
	TArray<UBackpackCellWidget*> GetCells() const { return Cells; }

	UFUNCTION(BlueprintCallable)
	void GetRowColumn(int32 Index, int32& Row, int32& Column);

	UFUNCTION(BlueprintCallable)
	void SetCells(const TArray<UBackpackCellWidget*>& SetCells);

	UFUNCTION(BlueprintCallable)
	void AddCells(UBackpackCellWidget* AddCells);

	UFUNCTION(BlueprintCallable)
	void ClearCells();

	UFUNCTION(BlueprintCallable)
	void UpdateBackpack();

	UFUNCTION(BlueprintCallable)
	void SelectItemByType(EItemType Type);

	UFUNCTION(BlueprintCallable)
	TArray<FItemInBackpackState> GetItems();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SwitchBackpack();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowDetectActorBar();

	UFUNCTION(BlueprintImplementableEvent)
	void HideDetectActorBar();

	UPROPERTY()
	TArray<UBackpackCellWidget*> Cells;
};
