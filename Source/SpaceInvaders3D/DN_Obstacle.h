// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Math/Vector.h"
#include "Math/UnrealMathUtility.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

#include "DN_Obstacle.generated.h"

UCLASS()
class SPACEINVADERS3D_API ADN_Obstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADN_Obstacle();


	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* CollisionSubComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* ObstacleStaticMeshSubComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		URotatingMovementComponent* RotatingMovementSubComponent;


	UFUNCTION(BlueprintCallable)
		void MoveAccordingToSpeed(float DeltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector MovementDirection = FVector(-1.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ScaleMinimum = 0.7f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ScaleMaximum = 1.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpeedMinimum = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpeedMaximum = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RotationMinimum = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RotationMaximum = 360.0f;

	UFUNCTION(BlueprintCallable)
		void InitializeActorScale();

	UFUNCTION(BlueprintCallable)
		void InitializeActorSpeed();

	UFUNCTION(BlueprintCallable)
		void InitializeActorRotationRate();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
