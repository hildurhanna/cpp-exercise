// Copyright Epic Games, Inc. All Rights Reserved.


#include "exercisesGameModeBase.h"

void AexercisesGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) 
{
	Super::InitGame(MapName, Options, ErrorMessage);
	StatueManager = GetWorld()->SpawnActor<AStatueManager>();
	StatueManager->Initialize(StatueClass);

}

void AexercisesGameModeBase::SpawnStatue(const FVector Location)
{
	StatueManager->SpawnStatue(Location);
}

