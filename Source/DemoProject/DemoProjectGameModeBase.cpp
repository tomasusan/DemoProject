// Copyright Epic Games, Inc. All Rights Reserved.


#include "DemoProjectGameModeBase.h"
#include "Character/BaseCharacter.h"

ADemoProjectGameModeBase::ADemoProjectGameModeBase()
{
	DefaultPawnClass = ABaseCharacter::StaticClass();
}
