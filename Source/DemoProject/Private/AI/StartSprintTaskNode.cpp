// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/StartSprintTaskNode.h"

#include "AIController.h"
#include "BaseEnemyCharacter.h"

UStartSprintTaskNode::UStartSprintTaskNode()
{
	NodeName = "StartSprint";
}

EBTNodeResult::Type UStartSprintTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();

	const auto Character = Cast<ABaseEnemyCharacter>(Controller->GetPawn());
	Character->SetIsSprint(true);

	return EBTNodeResult::Type::Succeeded;
}
