// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "StartSprintTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UStartSprintTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
public:

	UStartSprintTaskNode();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
