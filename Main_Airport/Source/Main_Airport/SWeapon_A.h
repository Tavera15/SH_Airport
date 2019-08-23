// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon_A.generated.h"

class UStaticMeshComponent;
class AProjectile_A;

UCLASS()
class MAIN_AIRPORT_API ASWeapon_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon_A();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<AProjectile_A> ProjectileBlueprint;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float BaseDamage = 20.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float Ammo = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		bool IsInfiniteAmmo = false;

	void SpawnProjectile(FVector, FRotator);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	AActor* MyOwner;
};
