// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StatueManager.h"
#include "ObjectSpawnPoint.generated.h"

UCLASS()
class EXERCISES_API AObjectSpawnPoint : public AActor
{
	GENERATED_BODY()
	
private:	
	// Sets default values for this actor's properties
	UPROPERTY()
		AStatueManager* StatueManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AObjectSpawnPoint();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
		int32 SpawnCount;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
		float SpawnRadius;

};
