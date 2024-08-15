// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CallAttackNotifyState.generated.h"

DECLARE_MULTICAST_DELEGATE(CallAttackSignature);

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UCallAttackNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
public:
	CallAttackSignature CallAttackDelegate;
	CallAttackSignature EndAttackDelegate;
};
