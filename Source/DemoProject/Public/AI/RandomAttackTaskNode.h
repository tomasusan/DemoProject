// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "RandomAttackTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API URandomAttackTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

public:
	URandomAttackTaskNode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
