// Fill out your copyright notice in the Description page of Project Settings.

#include "Storage_A.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AStorage_A::AStorage_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent_AC>(FName("InventoryComponent"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));

	RootComponent = Root;
	StaticMesh->AttachTo(Root);
	
}

// Called when the game starts or when spawned
void AStorage_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStorage_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

 