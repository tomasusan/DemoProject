// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CheckToPlayerDistanceDecorator.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UCheckToPlayerDistanceDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                                 uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !BlackBoard) return false;

	if (MaxPaceDistance < BlackBoard->GetValueAsFloat(ToPlayerDistance.SelectedKeyName))
	{
		return true;
	}
	return false;
}

UCheckToPlayerDistanceDecorator::UCheckToPlayerDistanceDecorator()
{
	NodeName = "CheckToPlayerDistance";
}
