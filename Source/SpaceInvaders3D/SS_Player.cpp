// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Player.h"

// Sets default values
ASS_Player::ASS_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	ParticleSystems = CreateAbstractDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ExplosionFX = CreateAbstractDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionFX"));
	SpaceShipMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceShipMesh"));
	CollisionComponent = CreateAbstractDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
	DeathExplosionSound = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("DeathExplosionSound"));

	// Attaching all of the components defined above to the root component, i.e. "RootComponent".
	ParticleSystems->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ExplosionFX->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpaceShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	DeathExplosionSound->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ASS_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

