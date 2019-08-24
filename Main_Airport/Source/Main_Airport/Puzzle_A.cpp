// Fill out your copyright notice in the Description page of Project Settings.

#include "Puzzle_A.h"
#include "DoorAction_AC.h"

bool APuzzle_A::IsValidItem(AItem_A* ItemToAdd)
{
	for (int i = 0; i < PuzzleKeys.Num(); i++)
	{
		if (PuzzleKeys[i]->ItemStructure.ID == ItemToAdd->ItemStructure.ID)
			return true;
	}
	return false;
}

void APuzzle_A::CheckPuzzle()
{
	for (int i = 0; i < PuzzleKeys.Num(); i++)
	{
		if (InventoryComponent->Inventory[i].TestItem->ItemStructure.ID == 0)
		{
			return;
		}
	}

	IsPuzzleCompleted = true;

	RewardPlayer();
}

void APuzzle_A::RewardPlayer()
{
	if (IsPuzzleCompleted != true) { return; }

	if (RewardType == Reward::REWARD_Spawn)
	{
		if (!ItemToSpawnBPClass) { return; }

		auto ItemSpawned = GetWorld()->SpawnActor<AItem_A>(ItemToSpawnBPClass, Transform);
		if (ItemSpawned)
		{
			UE_LOG(LogTemp, Warning, TEXT("Item Spawned"));
		}
	}
	else if (RewardType == Reward::REWARD_Unlock)
	{
		auto DoorAC = Door->FindComponentByClass<UDoorAction_AC>();

		if (DoorAC)
		{
			DoorAC->IsUnlocked = true;
		}
	}
	else if(RewardType == Reward::REWARD_Event)
	{
		OnEventReward();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error On RewardPlayer"));
	}

}
