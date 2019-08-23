// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "ItemStructureCode.h"
#include "Item_A.h"
#include "SlotStructureCode.generated.h"

USTRUCT(BlueprintType)
struct FSlotStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FItemStruct Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AItem_A* TestItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Quantity;

	FSlotStruct()
	{
		Item = FItemStruct::FItemStruct();
		TestItem = AItem_A::GetEmptyItem();
		TestItem->ItemStructure = Item;
		Quantity = 0;
	}

	bool operator==(const FSlotStruct& OtherItem) const
	{
		return TestItem->ItemStructure.ID == OtherItem.TestItem->ItemStructure.ID;		// Returns true if OtherItem is empty
	}
};
