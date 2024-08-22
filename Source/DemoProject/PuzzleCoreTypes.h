#pragma once
#include "Engine/DataTable.h"
#include "PuzzleCoreTypes.generated.h"

USTRUCT(BlueprintType)
struct FPuzzleInfo_1 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Puzzle")
	FString PuzzleID = "-1";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Puzzle")
	TArray<FTransform> Locations;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Puzzle")
	FString Order = "";
};
