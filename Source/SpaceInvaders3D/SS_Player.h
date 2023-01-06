// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"
#include "CustomGameMode.h"

#include "SS_Player.generated.h"

UCLASS()
class SPACEINVADERS3D_API ASS_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASS_Player();

	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* ParticleSystems;

	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* ExplosionFX;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SpaceShipMesh;

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CollisionComponent;

	UPROPERTY(EditAnywhere)
		UAudioComponent* DeathExplosionSound;
	
	// To limit the player going out of the width of the view
	UPROPERTY(EditAnywhere)
		float FieldWidth;

	// To limit the player going out of the height of the view
	UPROPERTY(EditAnywhere)
		float FieldHeight;

	UPROPERTY(EditAnywhere)
		float MaximumVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpaceShipScore = 0.0f;
	
	UFUNCTION(BlueprintCallable, Category = "FinalScore")
		virtual void UpdateHighScore();


	float CurrentVelocityX;
	float CurrentVelocityY;

	FVector CurrentLocation;
	FVector NewLocation;
	FRotator CurrentRotation;

	void MoveRight(float AxisValue);
	void MoveUp(float AxisValue);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
