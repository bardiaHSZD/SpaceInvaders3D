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

