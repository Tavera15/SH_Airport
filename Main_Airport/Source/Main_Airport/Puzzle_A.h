// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Storage_A.h"
#include "Puzzle_A.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class Reward : uint8
{
	REWARD_Spawn,
	REWARD_Unlock,
	REWARD_Event
};

UCLASS()
class MAIN_AIRPORT_API APuzzle_A : public AStorage_A
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AItem_A*> PuzzleKeys;

	UFUNCTION(BlueprintCallable)
		bool IsValidItem(AItem_A* ItemToAdd);

	UFUNCTION(BlueprintCallable)
		void CheckPuzzle();

	UPROPERTY(EditAnywhere)
		Reward RewardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<AItem_A> ItemToSpawnBPClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<AActor> DoorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* Door;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector LocationToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FRotator SpawnItemRotation;

	UFUNCTION(BlueprintImplementableEvent, Category = "Reward")
		void OnEventReward();


private:
	void RewardPlayer();
	bool IsPuzzleCompleted = false;
	
};
