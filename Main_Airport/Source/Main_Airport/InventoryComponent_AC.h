// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotStructureCode.h"
#include "Components/InputComponent.h"
#include "Item_A.h"
#include "InventoryComponent_AC.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAIN_AIRPORT_API UInventoryComponent_AC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent_AC();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		FString InventoryName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		int NumberOfSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<FSlotStruct> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
		TSubclassOf<class UUserWidget> InventoryWindowClass;

	UPROPERTY(BlueprintReadOnly)
		UUserWidget* InventoryWindow = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
		FVector2D WindowPosition;

	UFUNCTION(BlueprintCallable)
		bool CanCreateStack(AItem_A* ItemToAdd);

	UFUNCTION(BlueprintCallable)
		void AddToWindow();

	UFUNCTION(BlueprintCallable)
		FSlotStruct GetEmptySlot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<AItem_A*> InventoryItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	void PrepareInventory();
	bool SetupInputComponent();
	void AddToInventory();
	void InteractWithOtherInventory();
	void OpenOwnInventory();
	void InteractWithPuzzleActor();
	void OpenOtherInventory(UClass*);

	UInputComponent* InputComponent = nullptr;
	bool IsInventoryWindowOnViewport = false;
};
