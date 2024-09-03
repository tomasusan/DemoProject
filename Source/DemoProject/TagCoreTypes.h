#pragma once
#include "Engine/DataTable.h"

#include "TagCoreTypes.generated.h"

UENUM(BlueprintType)
enum class ETagType:uint8
{
	None,
	HealMini,
	HealMedium,
	HealMax,
	Sword,
	LifeRing,
	End
};

UENUM(BlueprintType)
enum class ETagMonitorType:uint8
{
	LongTerm,
	SHortTerm
};

USTRUCT(BlueprintType)
struct FCommonTagCountCheckEventInfo:public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString MissionID = "Invalid ID";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ETagMonitorType MonitorType = ETagMonitorType::LongTerm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<int32, int32> MonitorTargets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FText Description;

	TMap<ETagType, bool> MonitorStates;
};