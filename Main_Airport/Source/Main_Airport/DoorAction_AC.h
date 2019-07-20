// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorAction_AC.generated.h"

UENUM(BlueprintType)
enum class DoorSide : uint8 {
	Left,
	Right
};

UENUM()
enum class DoorStatus : uint8 {
	Closed,
	Opened
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAIN_AIRPORT_API UDoorAction_AC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorAction_AC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
		DoorSide Doorside;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
		DoorStatus Doorstatus;

	UPrimitiveComponent* theDoor;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
