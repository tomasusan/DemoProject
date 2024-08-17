// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DemoProject/ItemCoreTypes.h"
#include "BackpackCellWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UBackpackCellWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void UpdateCell(FItemInBackpackState Info, bool MakeDefault = false);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Info")
	FString ID;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Info")
	FString ItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Info")
	FString ItemNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Info")
	UTexture2D* Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Info")
	UTexture2D* DefaultIcon;
};
