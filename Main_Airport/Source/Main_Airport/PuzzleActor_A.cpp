// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleActor_A.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APuzzleActor_A::APuzzleActor_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent_AC>(FName("InventoryComponent"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	
	RootComponent = Root;

	StaticMesh->AttachTo(Root);
}

// Called when the game starts or when spawned
void APuzzleActor_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzleActor_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
