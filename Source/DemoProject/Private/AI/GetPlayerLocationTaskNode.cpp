// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GetPlayerLocationTaskNode.h"

#include "AIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/BaseEnemyCharacter.h"

UGetPlayerLocationTaskNode::UGetPlayerLocationTaskNode()
{
	NodeName = "GetPlayerLocation";
}

EBTNodeResult::Type UGetPlayerLocationTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	
	const auto PlayerCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();


	BlackBoard->SetValueAsVector(DestinationLocationKey.SelectedKeyName, PlayerCharacter->GetActorLocation());

	return EBTNodeResult::Type::Succeeded;
}
