// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "StopSprintTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UStopSprintTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

public:

	UStopSprintTaskNode();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
