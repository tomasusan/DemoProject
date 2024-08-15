// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/ProcessFirstMoveTaskNode.h"

#include "AIController.h"
#include "BaseEnemyCharacter.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

DEFINE_LOG_CATEGORY_STATIC(TaskLog, All, All);

UProcessFirstMoveTaskNode::UProcessFirstMoveTaskNode()
{
	NodeName = "ProcessFirstMove";
}

EBTNodeResult::Type UProcessFirstMoveTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UE_LOG(TaskLog, Warning, TEXT("Begin Process First Move"));
	
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	
	const auto Character = Cast<ABaseEnemyCharacter>(Controller->GetPawn());
	if(!Character)
	{
	UE_LOG(TaskLog, Warning, TEXT("No Owner Cast"));
		return EBTNodeResult::Type::Failed;
	}

	const auto PlayerCharacter = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if(!PlayerCharacter)
	{
	UE_LOG(TaskLog, Warning, TEXT("No Player Pawn Cast"));
		return EBTNodeResult::Type::Failed;
	}

	const FVector DistanceVector = PlayerCharacter->GetActorLocation() - Character->GetActorLocation();
	const FVector Direction = DistanceVector.GetSafeNormal();

	const float FullLength = FMath::Abs(DistanceVector.Length());
	if(FullLength < CheckRadius)
	{
		UE_LOG(TaskLog, Error, TEXT("No need First Move"));
		BlackBoard->SetValueAsBool(NeedFirstMove.SelectedKeyName, false);
		return EBTNodeResult::Type::Succeeded;
	}
	
	const float DesiredLength = FullLength - CheckRadius;
	
	const FVector DesiredLocation = Direction * DesiredLength;

	BlackBoard->SetValueAsVector(DestinationLocationKey.SelectedKeyName, DesiredLocation);
	BlackBoard->SetValueAsBool(NeedFirstMove.SelectedKeyName, false);
	UE_LOG(TaskLog, Warning, TEXT("All Success"));

	return EBTNodeResult::Type::Succeeded;
}
