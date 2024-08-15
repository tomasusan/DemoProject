// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/CommoAnimNotify23.h"

void UCommoAnimNotify23::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	OnNotified.Broadcast();
}
