// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseEnemyCharacter.h"

void ABaseEnemyCharacter::OnEntryAnim()
{
	InAnim = true;
}

void ABaseEnemyCharacter::OnOutAnim()
{
	InAnim = false;
}

void ABaseEnemyCharacter::Skill_1()
{
}

void ABaseEnemyCharacter::Skill_2()
{
}

void ABaseEnemyCharacter::Die()
{
}
