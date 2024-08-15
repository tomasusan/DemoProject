// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SetFocusTaskNode.h"

#include "AIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

DEFINE_LOG_CATEGORY_STATIC(TaskLog, All, All);

USetFocusTaskNode::USetFocusTaskNode()
{
	NodeName = "SetFocus";
}

EBTNodeResult::Type USetFocusTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	
	if(!BlackBoard->GetValueAsBool(DetectedState.SelectedKeyName))
	{
		Controller->ClearFocus(EAIFocusPriority::Gameplay);
		return EBTNodeResult::Type::Succeeded;
	}

	const auto PlayerPawn = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerPawn)
	{
		return EBTNodeResult::Type::Failed;
	}

	Controller->SetFocus(PlayerPawn);

	return EBTNodeResult::Type::Succeeded;
}
