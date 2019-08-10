// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySlot_UW.h"


void UInventorySlot_UW::test2()
{
	if (!SlotContentToAdd)
	{
		UE_LOG(LogTemp, Warning, TEXT("test2 fail"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("test2 Pass"));
}
