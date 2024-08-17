// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoProject/ItemCoreTypes.h"
#include "ItemActor.generated.h"

UCLASS()
class DEMOPROJECT_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Compoennt")
	FItemBasicInfo BasicInfo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Info")
	UDataTable* DataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Info")
	FName ID = "-1";

private:
	void InitInfo();

};
