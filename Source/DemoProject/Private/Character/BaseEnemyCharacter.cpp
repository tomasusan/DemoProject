// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseEnemyCharacter.h"

void ABaseEnemyCharacter::RandomAttack()
{
}

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

void ABaseEnemyCharacter::InitAnimNotify()
{
}

bool ABaseEnemyCharacter::GeneratePossibleAttack()
{
	const float Random = FMath::RandRange(0.f, 100.f);
	if (Random <= 100 * AttackPossibility) return true;
	return false;
}
