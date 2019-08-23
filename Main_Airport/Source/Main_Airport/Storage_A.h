// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryComponent_AC.h"
#include "Collision.h"
#include "Storage_A.generated.h"

UCLASS()
class MAIN_AIRPORT_API AStorage_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStorage_A();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInventoryComponent_AC* InventoryComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
};
 