// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActor.h"

DEFINE_LOG_CATEGORY_STATIC(ItemLog, All, All);

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());

	
	
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
    InitInfo();

	UE_LOG(ItemLog, Warning, TEXT("%s"), *BasicInfo.ItemName.ToString());
	
}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemActor::InitInfo()
{
	if(!DataTable) return;
	if(const auto RowInfo = DataTable->FindRow<FItemBasicInfo>(ID, "Get Info", true))
		BasicInfo = *RowInfo;
}
