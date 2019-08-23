// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile_A.h"

// Sets default values
AProjectile_A::AProjectile_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile_A::LaunchProjectile(float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Projectie fires at: %f"), Speed);
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}

