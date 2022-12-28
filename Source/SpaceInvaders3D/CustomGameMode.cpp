// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameMode.h"
#include "CustomGameState.h"
#include <Engine/Engine.h>

ACustomGameMode::ACustomGameMode()
{
	GameStateClass = ACustomGameMode::StaticClass(); // StaticClass is Unreal GC Methodology
}

int32 ACustomGameMode::GetFinalScore() const
{
	return GetGameState<ACustomGameState>()->FinalScore;
}

void ACustomGameMode::SetFinalScore(int32 NewFinalScore) const
{
	GetGameState<ACustomGameState>()->FinalScore = NewFinalScore;
}

int32 ACustomGameMode::GetMaximumFinalScore() const
{
	return GetGameState<ACustomGameState>()->MaximumFinalScore;
}

void ACustomGameMode::SetMaximumFinalScore(int32 NewMaximumFinalScore) const
{
	GetGameState<ACustomGameState>()->MaximumFinalScore = NewMaximumFinalScore;
}

// This is called before anything else is called, and none of the default
// blueprints provide access to this function.

void ACustomGameMode::StartPlay()
{
	//  For debugging purposes only
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Start Play is Called ..."));
	
	StartPlayEvent();

	GetWorld()->GetAuthGameMode()->GetGameState<ACustomGameState>()->FinalScore = 0;

	GetWorld()->GetAuthGameMode()->GetGameState<ACustomGameState>()->MaximumFinalScore = 0;

	Super::StartPlay();
}

void ACustomGameMode::StartPlayEvent_Implementation()
{
	//  For debugging purposes only
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Start Play Event Implementation is Called ..."));

}





