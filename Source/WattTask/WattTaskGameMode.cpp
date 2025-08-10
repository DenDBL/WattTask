// Copyright Epic Games, Inc. All Rights Reserved.

#include "WattTaskGameMode.h"
#include "WattTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWattTaskGameMode::AWattTaskGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
