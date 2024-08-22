// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Interactable/BaseInteractableActor.h"
#include "PuzzleActor_1.generated.h"

class UTextRenderComponent;
DECLARE_MULTICAST_DELEGATE_OneParam(FTriggeredSignature, int32);

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API APuzzleActor_1 : public ABaseInteractableActor
{
	GENERATED_BODY()

public:
	APuzzleActor_1();

	virtual void Interact_Implementation(AActor* InstigatorActor) override;

	virtual void BeginPlay() override;

	FTriggeredSignature TriggeredDelegate;

	virtual void SetIndex(const int32 NewIndex) override;

	void ResetState();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UStaticMeshComponent* Mesh_1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UStaticMeshComponent* Mesh_2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UTextRenderComponent* TextComponent;

private:
	bool ShowMesh_2 = false;

	void SwitchShowMesh_2();
};
