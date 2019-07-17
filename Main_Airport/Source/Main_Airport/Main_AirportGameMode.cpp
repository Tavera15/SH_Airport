// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Main_AirportGameMode.h"
#include "Main_AirportCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMain_AirportGameMode::AMain_AirportGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
