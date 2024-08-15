// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetFocusTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API USetFocusTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
public:
	USetFocusTaskNode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector DetectedState;
};
