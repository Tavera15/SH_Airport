// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorAction_AC.h"
#include "Engine/StaticMesh.h"
#include "EngineUtils.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "InventoryComponent_AC.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UDoorAction_AC::UDoorAction_AC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorAction_AC::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UDoorAction_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...

	if (IsKeyOnPlate()) {
		OnOpen.Broadcast();
	}
}


bool UDoorAction_AC::IsKeyOnPlate() 
{
	if (!PressurePlate) { return false; }
	
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	
	if (OverlappingActors.Num() != 0 && CanUnlockDoor())
		return true;
	
	return false;
}
 
bool UDoorAction_AC::CanUnlockDoor()
{
	if (IsUnlocked == true) { return true; }

	auto PlayerInventoryComp = Player->FindComponentByClass<UInventoryComponent_AC>();
	if (!PlayerInventoryComp || !DoorKey) { return false; }
	
	auto PlayerInventory = PlayerInventoryComp->Inventory;

	for (int i = 0; i < PlayerInventoryComp->NumberOfSlots; i++)
	{
		if (PlayerInventory[i].TestItem->ItemStructure.ID == DoorKey->ItemStructure.ID)
		{
			PlayerInventoryComp->Inventory[i] = PlayerInventoryComp->GetEmptySlot();
			PlayerInventoryComp->AddToWindow();
			IsUnlocked = true;
			return true;
		}
	}

	return false;
}