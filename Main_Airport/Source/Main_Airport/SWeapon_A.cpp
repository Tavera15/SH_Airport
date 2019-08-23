// Fill out your copyright notice in the Description page of Project Settings.

#include "SWeapon_A.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Projectile_A.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASWeapon_A::ASWeapon_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ASWeapon_A::BeginPlay()
{
	Super::BeginPlay();
	MyOwner = GetOwner();
}

// Called every frame
void ASWeapon_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASWeapon_A::Fire()
{
	if (!MyOwner) { return; }

	if (!IsInfiniteAmmo && Ammo <= 0) { return; }

	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * 10000);
	TArray<AActor*> IgnoredActors = { MyOwner, this };
	
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActors(IgnoredActors);
	QueryParams.bTraceComplex = true;

	FHitResult Hit;
	
	if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, ECC_Visibility, QueryParams))
	{
		auto ActorHit = Hit.GetActor();
		UGameplayStatics::ApplyPointDamage(ActorHit, BaseDamage, EyeLocation, Hit, MyOwner->GetInstigatorController(), this, DamageType);
		UE_LOG(LogTemp, Warning, TEXT("Ouch"));
	}

	if (!ProjectileBlueprint) {
		UE_LOG(LogTemp, Warning, TEXT("No Projectile BP"));
		return; 
	}

	SpawnProjectile(EyeLocation, EyeRotation);

	Ammo -= 20;

	DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::Blue, 3.0f, 1.0f);
}

void ASWeapon_A::SpawnProjectile(FVector EyeLocation, FRotator EyeRotation)
{
	ACharacter* myCharacter = Cast<ACharacter>(MyOwner);

	if (!myCharacter) { return; }

	auto Projectile = GetWorld()->SpawnActor<AProjectile_A>(
		ProjectileBlueprint,
		EyeLocation,
		EyeRotation
		);

	Projectile->LaunchProjectile(4000.f);
} 