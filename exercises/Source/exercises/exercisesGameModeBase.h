// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StatueManager.h"
#include "Statue.h"
#include "exercisesGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class EXERCISES_API AexercisesGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
		AStatueManager* StatueManager;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSoftClassPtr<AStatue> StatueClass;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UFUNCTION()
		void SpawnStatue(const FVector Location);
	
};
