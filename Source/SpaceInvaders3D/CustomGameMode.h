// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	
	virtual void StartPlay();

	UFUNCTION(BlueprintNativeEvent, Category = "FinalScore", DisplayName="Start Play")
		void StartPlayEvent();
	
};
