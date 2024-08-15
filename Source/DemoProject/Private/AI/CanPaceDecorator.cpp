// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CanPaceDecorator.h"

#include "BehaviorTree/BlackboardComponent.h"

bool UCanPaceDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if(!BlackBoard) return false;

	if(BlackBoard->GetValueAsFloat(ToPlayerDistance.SelectedKeyName) <= MaxPaceDistance)
		return true;
	return false;
}
