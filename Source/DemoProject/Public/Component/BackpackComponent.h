// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoProject/ItemCoreTypes.h"
#include "BackpackComponent.generated.h"


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
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	TArray<FItemInBackpackState> GetItemsToBackpack() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BackpackComponent")
	UDataTable* Datatable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BackpackComponent")
	TArray<FName> Items_ID;

	void BackpackAdd(const FItemInBackpackState& NewItem);

private:
	void LoadToBackpack(TArray<FName> NewItems);

	TArray<FItemInBackpackState> Items;
};
