// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ComboAnimNotify12.h"

void UComboAnimNotify12::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	OnNotified.Broadcast();
}
