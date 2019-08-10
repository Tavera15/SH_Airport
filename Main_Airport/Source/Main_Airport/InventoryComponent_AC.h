// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotStructureCode.h"
#include "Components/InputComponent.h"
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

	void PrepareInventory();
	bool CanCreateStack(FItemStruct);
	bool SetupInputComponent();
	void AddToInventory();
	void AddToWindow();

	void InteractWithOtherInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UInputComponent* InputComponent = nullptr;
	bool IsInventoryWindowOnViewport = false;
};
