// Fill out your copyright notice in the Description page of Project Settings.


#include "DN_Obstacle.h"

// Sets default values
ADN_Obstacle::ADN_Obstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




	RootComponent = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	ObstacleStaticMeshSubComponent = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleStaticMeshSubComponent"));
	CollisionSubComponent = CreateAbstractDefaultSubobject<USphereComponent>(TEXT("CollisionSubComponent"));
	RotatingMovementSubComponent = CreateAbstractDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovementSubComponent"));

	// Attaching all of the components defined above to the root component, i.e. "RootComponent".
	ObstacleStaticMeshSubComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionSubComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);



}

void ADN_Obstacle::MoveAccordingToSpeed(float DeltaSeconds)
{
	const FVector DeltaMove = DeltaSeconds * CurrentSpeed * MovementDirection;
	AddActorWorldOffset(DeltaMove);
}

void ADN_Obstacle::InitializeActorScale()
{
	float NewScaleCoefficient = FMath::RandRange(ScaleMinimum, ScaleMaximum);
	FVector NewScale3DVector = FVector(NewScaleCoefficient, NewScaleCoefficient, NewScaleCoefficient);
	SetActorScale3D(NewScale3DVector);
}

void ADN_Obstacle::InitializeActorSpeed()
{
	float InitialCurrentSpeed = FMath::RandRange(SpeedMinimum, SpeedMaximum);
	CurrentSpeed = InitialCurrentSpeed;
}

void ADN_Obstacle::InitializeActorRotationRate()
{
	float RollRotationRate = FMath::RandRange(RotationMinimum, RotationMaximum);
	float PitchRotationRate = FMath::RandRange(RotationMinimum, RotationMaximum);
	float YawRotationRate = 0.0f;
	FRotator InitialRotationRate = FRotator(RollRotationRate, PitchRotationRate, YawRotationRate);
	RootComponent->AddRelativeRotation(InitialRotationRate);
}

// Called when the game starts or when spawned
void ADN_Obstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADN_Obstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

