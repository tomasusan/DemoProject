// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UIComponent.generated.h"


class UBackpackMainWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOPROJECT_API UUIComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUIComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> MainWidgetClass;
	
	UFUNCTION()
	void SwitchBackpack();

	void ShowDetectBar() const;
	void HideDetectBar() const;

	void InitUI();
	
private:
	UPROPERTY()
	UBackpackMainWidget* MainWidget;

	bool BackpackOpen = false;
		
};
