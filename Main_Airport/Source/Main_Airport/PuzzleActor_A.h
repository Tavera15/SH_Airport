// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_A.h"
#include "InventoryComponent_AC.h"
#include "PuzzleActor_A.generated.h"

UCLASS()
class MAIN_AIRPORT_API APuzzleActor_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleActor_A();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USceneComponent* Root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInventoryComponent_AC* InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AItem_A*> PuzzleKeys;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DoesItSpawnKey;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	

};
