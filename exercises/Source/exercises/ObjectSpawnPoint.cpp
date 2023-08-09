// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectSpawnPoint.h"
#include "DrawDebugHelpers.h"
#include "StatueManager.h"
#include "kismet/GameplayStatics.h"

// Sets default values
AObjectSpawnPoint::AObjectSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	StatueManager = Cast<AStatueManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AStatueManager::StaticClass()));
	auto Location = GetActorLocation();
	for (int i = 0; i < SpawnCount; i++)
	{
		StatueManager->SpawnStatue(Location);
	}

	
	
}

// Called every frame
void AObjectSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), SpawnRadius, 12, FColor::Red);

}

