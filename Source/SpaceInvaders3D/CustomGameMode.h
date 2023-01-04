// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SpaceInvaders3D.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

#include "GameFramework/GameModeBase.h"
#include "CustomGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS3D_API ACustomGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ACustomGameMode();



	UPROPERTY(BlueprintReadWrite)
		int32 FinalScore;

	UPROPERTY(BlueprintReadWrite)
		int32 MaximumFinalScore;

	/** Return the final score recorded in the current game*/
	UFUNCTION(BlueprintPure, Category="FinalScore")
		virtual int32 GetFinalScore() const;

	/** Sets the final score recorded in the current game*/
	// Has exec wire in and out
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual void SetFinalScore(int32 NewFinalScore) const;

	/** Return the maximum final score recorded*/
	UFUNCTION(BlueprintPure, Category = "FinalScore")
		virtual int32 GetMaximumFinalScore() const;

	/** Sets the maximum final score recorded in the current game*/
	// Has exec wire in and out
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual void SetMaximumFinalScore(int32 NewMaximumFinalScore) const;

	/** Write USTRUTC score to file*/
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual void WriteSerializedScore(FBestPlayer CurrentPlayer) const;
	
	/** Read USTRUTC score to file*/
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual FBestPlayer ReadDeSerializedScore();
	
	/** Enumeration to Determine Level Difficulty*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<DifficultyType> LevelDifficulty;

	/** Write USTRUTC score to file*/
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual void WriteSerializedLevel(FPlayerDifficulty CurrentDifficultyLevel) const;

	/** Read USTRUTC score to file*/
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual FPlayerDifficulty ReadDeSerializedLevel();
};
