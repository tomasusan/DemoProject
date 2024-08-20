// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Interactable/BaseInteractableActor.h"
#include "DemoProject/ItemCoreTypes.h"
#include "BasePickableActor.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class DEMOPROJECT_API ABasePickableActor : public ABaseInteractableActor
{
	GENERATED_BODY()

public:
	ABasePickableActor();

	virtual void BeginPlay() override;
	
	virtual void Interact_Implementation(AActor* InstigatorActor) override;

	UFUNCTION(BlueprintCallable)
	void LoadInfo(FName ID);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UStaticMeshComponent* ActorMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	UDataTable* DataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemInfo")
	FName ItemID;

private:
	FItemBasicInfo BasicInfo;
};
