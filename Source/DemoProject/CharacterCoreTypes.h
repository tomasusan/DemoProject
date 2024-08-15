#pragma once
#include "CharacterCoreTypes.generated.h"

USTRUCT(BlueprintType)
struct FComboInfo
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	bool CanCombo = false;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	bool WantCombo = false;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	bool InAnim = false;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	int32 CurrentWantCombo = -1;
};

USTRUCT(BlueprintType)
struct FImpactInfo
{
	GENERATED_BODY()
	
	FVector SourceLocation;
	FVector DesiredLocation;
	FVector DesiredDirection;
	float CurrentVelocity;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Accel = 100;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float InitVelocity = 600;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DeltaTime = 0.01;
};
