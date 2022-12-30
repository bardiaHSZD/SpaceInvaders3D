// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Math/Vector.h"

#include "DN_Obstacle.generated.h"

UCLASS()
class SPACEINVADERS3D_API ADN_Obstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADN_Obstacle();

	UFUNCTION(BlueprintCallable)
		void MoveAccordingToSpeed(float DeltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector MovementDirection = FVector(-1.0f, 0.0f, 0.0f);
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
