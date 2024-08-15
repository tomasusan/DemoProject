// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CheckToPlayerDistanceDecorator.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UCheckToPlayerDistanceDecorator : public UBTDecorator
{
	GENERATED_BODY()
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

public:
	UCheckToPlayerDistanceDecorator();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector ToPlayerDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float MaxPaceDistance;
};
