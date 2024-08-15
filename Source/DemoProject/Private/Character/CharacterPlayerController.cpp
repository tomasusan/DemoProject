// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterPlayerController.h"

ETeamAttitude::Type ACharacterPlayerController::GetTeamAttitudeTowards(const AActor& Other) const
{
	return ETeamAttitude::Type::Hostile;
}
