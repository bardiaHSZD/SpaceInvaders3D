// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders3D.generated.h"

USTRUCT(BlueprintType)
struct FBestPlayer
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "CurrentScore")
		int32 CurrentScore;

	UPROPERTY(BlueprintReadWrite, Category = "CurrentScore")
		int32 BestCurrentScore;
};

UENUM(BlueprintType)
enum DifficultyType
{
	Easy,
	Medium,
	Hard
};

USTRUCT(BlueprintType)
struct FPlayerDifficulty
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "DifficultyLevel")
		FString CurrentDifficulty;
};