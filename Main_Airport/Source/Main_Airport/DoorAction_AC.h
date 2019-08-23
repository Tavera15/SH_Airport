// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Engine/TriggerVolume.h"
#include "Item_A.h"
#include "DoorAction_AC.generated.h"

UENUM(BlueprintType)
enum class DoorSide : uint8 {
	Left,
	Right
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAIN_AIRPORT_API UDoorAction_AC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorAction_AC();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		DoorSide Doorside;

	UPROPERTY(EditInstanceOnly, Category = "Door")
		ACharacter* Player = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		bool IsUnlocked;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	

	bool CanUnlockDoor();
	bool IsKeyOnPlate();
};
 