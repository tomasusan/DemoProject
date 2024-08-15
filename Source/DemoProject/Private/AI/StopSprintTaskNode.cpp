// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/StopSprintTaskNode.h"

#include "AIController.h"
#include "BaseEnemyCharacter.h"

UStopSprintTaskNode::UStopSprintTaskNode()
{
	NodeName = "StopSprint";
}

EBTNodeResult::Type UStopSprintTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();

	const auto Character = Cast<ABaseEnemyCharacter>(Controller->GetPawn());
	Character->SetIsSprint(false);

	return EBTNodeResult::Type::Succeeded;
}
