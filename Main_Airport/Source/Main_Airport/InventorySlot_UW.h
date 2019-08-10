// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SizeBox.h"
#include "SlotStructureCode.h"
#include "InventorySlot_UW.generated.h"

/**
 * 
 */
UCLASS()
class MAIN_AIRPORT_API UInventorySlot_UW : public UUserWidget
{
	GENERATED_BODY()
	
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SlotDetails")
		USizeBox* sizebox;


	FSlotStruct* SlotContentToAdd;

	void test2();
	

};

// https://answers.unrealengine.com/questions/470481/create-widget-in-pure-c.html
// https://answers.unrealengine.com/questions/570065/setting-up-widget-elements-in-constructor-of-uuser.html