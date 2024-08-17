// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CheckDistanceService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

DEFINE_LOG_CATEGORY_STATIC(ServiceLog, All, All);

void UCheckDistanceService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !BlackBoard) return;

	const auto AICharacter = Controller->GetPawn();
	const auto PlayerCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!AICharacter || !PlayerCharacter) return;

	const auto FullDistanceVector = PlayerCharacter->GetActorLocation() - AICharacter->GetActorLocation();
	const auto FullLength = FMath::Abs(FullDistanceVector.Length());

	BlackBoard->SetValueAsFloat(ToPlayerDistance.SelectedKeyName, FullLength);

	//UE_LOG(ServiceLog, Warning, TEXT("To Player Distance: %f"), FullLength);
}

UCheckDistanceService::UCheckDistanceService()
{
	NodeName = "CheckDistance";

	bNotifyTick = true;
	bTickIntervals = true;
	bNotifyBecomeRelevant = false;
	bNotifyCeaseRelevant = true;
}
