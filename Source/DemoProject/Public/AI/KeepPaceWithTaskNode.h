// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "KeepPaceWithTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UKeepPaceWithTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UKeepPaceWithTaskNode();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float DistanceTolerance = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector ToPlayerDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float MaxPaceDistance = 200.f;
};
