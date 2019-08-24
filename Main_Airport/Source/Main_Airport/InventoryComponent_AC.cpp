// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent_AC.h"
#include "Item_A.h"
#include "ItemStructureCode.h"
#include "InventoryWindow_UW.h"
#include "GameFramework/Actor.h"
#include "Storage_A.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "PuzzleActor_A.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

// Sets default values for this component's properties
UInventoryComponent_AC::UInventoryComponent_AC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInventoryComponent_AC::BeginPlay()
{
	Super::BeginPlay();
	// ...

	PrepareInventory();

	if (SetupInputComponent() && !GetOwner()->IsA(AStorage_A::StaticClass()))
	{
		AddToWindow();
	}
}


// Called every frame
void UInventoryComponent_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

void UInventoryComponent_AC::PrepareInventory() 
{
	auto temp = Inventory;
	Inventory.Init(FSlotStruct::FSlotStruct(), NumberOfSlots);
	
	for (int i = 0; i < NumberOfSlots; i++)
	{
		if (temp.IsValidIndex(i))
			Inventory[i] = temp[i];
	}
}

bool UInventoryComponent_AC::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Inventory", IE_Pressed, this, &UInventoryComponent_AC::AddToInventory);
		InputComponent->BindAction("Inventory_Interact", IE_Pressed, this, &UInventoryComponent_AC::InteractWithOtherInventory);
		InputComponent->BindAction("OpenInventory", IE_Pressed, this, &UInventoryComponent_AC::OpenOwnInventory);

		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s missing Input Component"), *GetOwner()->GetName());
		return false;
	}
}

void UInventoryComponent_AC::AddToInventory()
{
	TArray<AActor*> OverlappingItems;
	GetOwner()->GetOverlappingActors(OUT OverlappingItems, AItem_A::StaticClass());		// Gets actors of a certain Actor child class

	for (auto item : OverlappingItems)
	{
		auto MainItem = Cast<AItem_A>(item);
		FItemStruct TheItemStruct = MainItem->ItemStructure;
		
		if (CanCreateStack(MainItem))
		{
			item->SetActorHiddenInGame(true);
			item->SetActorEnableCollision(false);
			break;
		}
	}
}

bool UInventoryComponent_AC::CanCreateStack(AItem_A* ItemToAdd)
{
	FSlotStruct EmptySlot = FSlotStruct::FSlotStruct();

	for (int i = 0; i < NumberOfSlots; i++)
	{
		if (!Inventory.IsValidIndex(i) || Inventory[i].TestItem->ItemStructure.ID == EmptySlot.TestItem->ItemStructure.ID)
		{
			EmptySlot.Item = ItemToAdd->ItemStructure;
			EmptySlot.TestItem = ItemToAdd;
			EmptySlot.Quantity = 1;
			Inventory[i] = EmptySlot;
			AddToWindow();
			return true;
		}
	}
	return false;
}

void UInventoryComponent_AC::AddToWindow()
{
	if (!InventoryWindowClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("No InventoryWinow class in InventoryCompnent_AC, AddToWindow: Fail"));
		return;
	}

	if (InventoryWindow && InventoryWindow->IsInViewport())
	{
		InventoryWindow->RemoveFromViewport();
	}

	InventoryWindow = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), InventoryWindowClass);

	if (!InventoryWindow)
	{
		UE_LOG(LogTemp, Warning, TEXT("No InventoryWin in InventoryCompnent_AC, AddToWindow: Fail"));
		return;
	}

	InventoryWindow->SetAlignmentInViewport(FVector2D(.5, .5));
	InventoryWindow->SetPositionInViewport(WindowPosition);
	InventoryWindow->SetAnchorsInViewport(FAnchors(.5, .5, .5, .5));
	
	InventoryWindow->AddToViewport();
	UE_LOG(LogTemp, Warning, TEXT("InventoryCompnent_AC, AddToWindow : Pass: Owner: %d"), NumberOfSlots);
}

void UInventoryComponent_AC::InteractWithOtherInventory()
{
	TArray<AActor*> OverlappingSelfItems;
	GetOwner()->GetOverlappingActors(OUT OverlappingSelfItems, AStorage_A::StaticClass());		// Gets actors of a certain Actor child class

	for (auto item : OverlappingSelfItems)
	{
		auto StorageInventoryAC = item->FindComponentByClass<UInventoryComponent_AC>();
		if (StorageInventoryAC)
		{
			UE_LOG(LogTemp, Warning, TEXT("Storage Inventory has UInventoryAC: %s"), *item->GetName());
			StorageInventoryAC->AddToWindow();
			return;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failure"));
		}
	}
}

void UInventoryComponent_AC::OpenOwnInventory()
{
	if (!InventoryWindow) { return; }

	auto MyPlayerController = GetWorld()->GetFirstPlayerController();

	if (MyPlayerController->bShowMouseCursor)
	{
		MyPlayerController->bShowMouseCursor = false;
		MyPlayerController->SetInputMode(FInputModeGameOnly::FInputModeGameOnly());
		return;
	}

	MyPlayerController->bShowMouseCursor = true;
	MyPlayerController->SetInputMode(FInputModeGameAndUI::FInputModeGameAndUI());
}

FSlotStruct UInventoryComponent_AC::GetEmptySlot()
{
	//FSlotStruct EmptySlot = FSlotStruct::FSlotStruct();
	return FSlotStruct::FSlotStruct();
}
