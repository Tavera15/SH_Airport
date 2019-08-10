// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "ItemStructureCode.h"
#include "SlotStructureCode.generated.h"

USTRUCT(BlueprintType)
struct FSlotStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FItemStruct Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Quantity;

	FSlotStruct()
	{
		Item = FItemStruct::FItemStruct();
		Quantity = 0;
	}

	bool operator==(const FSlotStruct& OtherItem) const
	{
		return FSlotStruct().Item.ID == OtherItem.Item.ID;		// Returns true if OtherItem is empty
	}
};
