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

	MaximumVelocity = 250.0f;
	CurrentVelocityX = 0.0f;
	CurrentVelocityY = 0.0f;

}


// Called when the game starts or when spawned
void ASS_Player::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = this->GetActorLocation();
	CurrentRotation = this->GetActorRotation();
	

	ExplosionFX->Deactivate();
	DeathExplosionSound->Deactivate();


}

// Called every frame
void ASS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ((CurrentVelocityX != 0.0f) || (CurrentVelocityY != 0.0f)) {
		NewLocation = FVector(CurrentLocation.X + (CurrentVelocityX * DeltaTime), 
			                  CurrentLocation.Y + (CurrentVelocityY * DeltaTime),
			                  0.0f);
		this->SetActorLocation(NewLocation);

		CurrentLocation = NewLocation;


	}

	if (CurrentVelocityY > 0.1f) {
		this->SetActorRotation(FRotator(CurrentRotation.Pitch + 45.0f,
										CurrentRotation.Yaw,
										CurrentRotation.Roll));
	}
	else if (CurrentVelocityY < -0.1f) {
		this->SetActorRotation(FRotator(CurrentRotation.Pitch - 45.0f,
			CurrentRotation.Yaw,
			CurrentRotation.Roll));
	}
	else {
		this->SetActorRotation(FRotator(CurrentRotation));

	}

	if (this->GetActorLocation().X > FieldWidth)
		CurrentLocation = FVector(FieldWidth - 1.0f, CurrentLocation.Y, CurrentLocation.Z);

	if (this->GetActorLocation().X < -FieldWidth)
		CurrentLocation = FVector(-FieldWidth + 1.0f, CurrentLocation.Y, CurrentLocation.Z);
	
	if (this->GetActorLocation().Y > FieldHeight)
		CurrentLocation = FVector(CurrentLocation.X, FieldHeight - 1.0f, CurrentLocation.Z);

	if (this->GetActorLocation().Y < -FieldHeight)
		CurrentLocation = FVector(CurrentLocation.X, -FieldHeight + 1.0f, CurrentLocation.Z);
}// Tick

// Called to bind functionality to input
void ASS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASS_Player::MoveRight);
	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ASS_Player::MoveUp);


}



void ASS_Player::MoveRight(float AxisValue)
{
	CurrentVelocityX = MaximumVelocity * AxisValue;
}

void ASS_Player::MoveUp(float AxisValue)
{
	CurrentVelocityY = MaximumVelocity * AxisValue;
}
