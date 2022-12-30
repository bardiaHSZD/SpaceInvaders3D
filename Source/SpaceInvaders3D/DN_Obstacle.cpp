// Fill out your copyright notice in the Description page of Project Settings.


#include "DN_Obstacle.h"

// Sets default values
ADN_Obstacle::ADN_Obstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADN_Obstacle::MoveAccordingToSpeed(float DeltaSeconds)
{
	const FVector DeltaMove = DeltaSeconds * CurrentSpeed * MovementDirection;
	AddActorWorldOffset(DeltaMove);
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

