// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/BaseSwordActor.h"
#include "BaseCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(SwordLog, All, All);

void ABaseSwordActor::ApplyAttack()
{
	Super::ApplyAttack();
	//UE_LOG(SwordLog, Warning, TEXT("Now Sword Apply Damage"));

	const auto SocketStart = WeaponMeshComponent->GetSocketTransform(DamageStartSocketName).GetLocation();
	const auto SocketEnd = WeaponMeshComponent->GetSocketTransform(DamageEndSocketName).GetLocation();
	TArray<FHitResult> Results;
	GetWorld()->LineTraceMultiByChannel(Results, SocketStart, SocketEnd, ECC_Visibility);

	for(auto& Result:Results)
	{
		const auto HitActor = Cast<ABaseCharacter>(Result.GetActor());
		if(HitActor && !HitCharacterPool.Contains(HitActor))
		{
			HitCharacterPool.Add(HitActor);
			HitActor->GetHit();
			UE_LOG(SwordLog, Warning, TEXT("Hit: %s"), *HitActor->GetName())
		}
	}
}

void ABaseSwordActor::EndAttack()
{
	Super::EndAttack();

	//UE_LOG(SwordLog, Warning, TEXT("End Attack"));
}
