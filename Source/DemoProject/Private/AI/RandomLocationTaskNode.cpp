// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/RandomLocationTaskNode.h"

#include "AIController.h"
#include "BaseEnemyCharacter.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

URandomLocationTaskNode::URandomLocationTaskNode()
{
	NodeName = "RandomLocation";
}

EBTNodeResult::Type URandomLocationTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();

	Owner = Cast<ABaseEnemyCharacter>(Controller->GetPawn());
	if(!Owner) return EBTNodeResult::Failed;

	const auto NavSys = UNavigationSystemV1::GetCurrent(Owner);
	if(!NavSys) return EBTNodeResult::Failed;

	FNavLocation  NavLocation;
	const auto Found = NavSys->GetRandomReachablePointInRadius(Owner->GetActorLocation(), 300, NavLocation);
	if(!Found) return EBTNodeResult::Failed;


	BlackBoard->SetValueAsVector(AimLocationKey.SelectedKeyName, NavLocation);
	return EBTNodeResult::Succeeded;
}
