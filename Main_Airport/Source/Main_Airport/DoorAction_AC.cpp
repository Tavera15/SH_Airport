// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorAction_AC.h"
#include "Engine/StaticMesh.h"
#include "EngineUtils.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
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

	theDoor = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	if (Doorstatus == DoorStatus::Closed) {
		theDoor->SetRelativeRotation(FRotator(0, 30, 0));
	}
	
}


// Called every frame
void UDoorAction_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

