// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Statue.h"
#include "GameFramework/Info.h"
#include "StatueManager.generated.h"

/**
 * 
 */
UCLASS()
class EXERCISES_API AStatueManager : public AInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
		TArray<AStatue*> Instances;

	UPROPERTY()
		UClass* LoadedObject;

public:

	
	UFUNCTION()
	void SpawnStatue(FVector Location);

	UFUNCTION()
	void Initialize(const TSoftClassPtr<AStatue> StatueClass);

};
