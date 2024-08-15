// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/RandomAttackTaskNode.h"

#include "AIController.h"
#include "BaseEnemyCharacter.h"

URandomAttackTaskNode::URandomAttackTaskNode()
{
	NodeName = "RandomAttack";
}

EBTNodeResult::Type URandomAttackTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();

	if(!Controller || !BlackBoard) return EBTNodeResult::Failed;

	const auto Character = Cast<ABaseEnemyCharacter>(Controller->GetPawn());

	Character->RandomAttack();

	return EBTNodeResult::Succeeded;
}
