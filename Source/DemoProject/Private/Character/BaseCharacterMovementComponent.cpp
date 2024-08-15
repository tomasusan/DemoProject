// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacterMovementComponent.h"

#include "BaseCharacter.h"

float UBaseCharacterMovementComponent::GetMaxSpeed() const
{
	const auto Character = Cast<ABaseCharacter>(GetOwner());
	check(Character);
	if(Character->IsSprinting())
		return MaxSpeed * SprintModifier;
	return MaxSpeed;

}
