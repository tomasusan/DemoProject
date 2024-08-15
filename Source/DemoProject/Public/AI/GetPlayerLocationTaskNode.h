// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GetPlayerLocationTaskNode.generated.h"

class ABaseEnemyCharacter;
/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UGetPlayerLocationTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UGetPlayerLocationTaskNode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector DestinationLocationKey;
};
