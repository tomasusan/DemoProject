// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/DetectInputAnimNotify.h"

void UDetectInputAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	OnNotified.Broadcast();
}
