// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"

#include "PlayerCharacter.h"


void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BehaviorTree)
		RunBehaviorTree(BehaviorTree);
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if(Other.IsA<APlayerCharacter>())
	{
		return ETeamAttitude::Hostile;
	}

	return ETeamAttitude::Type::Friendly;
	
}
