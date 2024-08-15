// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/KeepPaceWithTaskNode.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UKeepPaceWithTaskNode::UKeepPaceWithTaskNode()
{
	NodeName = "KeepPaceWith";
}

EBTNodeResult::Type UKeepPaceWithTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if(!Controller || !BlackBoard) return EBTNodeResult::Type::Failed;

	// if(BlackBoard->GetValueAsFloat(ToPlayerDistance.SelectedKeyName) > MaxPaceDistance)
	// 	return EBTNodeResult::Type::Succeeded;

	const auto AICharacter = Controller->GetPawn();
	const auto PlayerCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!AICharacter || !PlayerCharacter) return EBTNodeResult::Type::Failed;

	const auto FullDistanceVector = PlayerCharacter->GetActorLocation() - AICharacter->GetActorLocation();
	const auto FullLength = FMath::Abs(FullDistanceVector.Length());
	const auto Direction = FullDistanceVector.GetSafeNormal();

	if(FullLength < DistanceTolerance) return EBTNodeResult::Type::Succeeded;

	const auto DesiredDistanceVector = Direction * (FullLength - DistanceTolerance);
	const auto DesiredDestination = AICharacter->GetActorLocation() + DesiredDistanceVector;

	Controller->MoveToLocation(DesiredDestination);

	//BlackBoard->SetValueAsVector(Destination.SelectedKeyName, Character->GetActorLocation());

	return EBTNodeResult::Type::Succeeded;
}
