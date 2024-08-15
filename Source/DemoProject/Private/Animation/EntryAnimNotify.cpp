// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/EntryAnimNotify.h"

void UEntryAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	OnNotified.Broadcast();
	
}
