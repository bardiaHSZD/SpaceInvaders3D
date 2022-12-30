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


void ACustomGameMode::WriteSerializedScore(FBestPlayer CurrentPlayer) const
{
	FString FilePath = "C:\\Users\\bardi\\OneDrive\\Documents\\Github\\Person.json";


	FString FileData = "";

	FString JSONPayload;
	FJsonObjectConverter::UStructToJsonObjectString(CurrentPlayer, JSONPayload, 0, 0);

	// TODO: Write to file here probably using File Helper

	const FString File = *FPaths::Combine(FPaths::GameSourceDir(), FApp::GetProjectName(), TEXT("temp.json"));
	FFileHelper::SaveStringToFile(
		JSONPayload,
		*File,
		FFileHelper::EEncodingOptions::AutoDetect,
		&IFileManager::Get()
	);
	

}

FBestPlayer ACustomGameMode::ReadDeSerializedScore()
{
	//FString FilePath = "C:\\Users\\bardi\\OneDrive\\Documents\\Github\\Person.json";
	const FString FilePath = *FPaths::Combine(FPaths::GameSourceDir(), FApp::GetProjectName(), TEXT("temp.json"));



	FString FileData = "";
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("DID NOT FIND FILE"));
	}

	FBestPlayer PersonJSON;
	FFileHelper::LoadFileToString(FileData, *FilePath);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *FileData);

	if (FJsonObjectConverter::JsonObjectStringToUStruct(FileData, &PersonJSON, 0, 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("CONVERTED"));
	}


	return PersonJSON;
}






