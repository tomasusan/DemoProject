// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ProcessFirstMoveTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UProcessFirstMoveTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UProcessFirstMoveTaskNode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float CheckRadius = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector DestinationLocationKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector NeedFirstMove;
	
};
