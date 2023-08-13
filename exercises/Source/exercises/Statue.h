// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpable.h"
#include "GameFramework/Actor.h"
#include "Statue.generated.h"

UCLASS()
class EXERCISES_API AStatue : public AActor, public IPickUpable 
{
	GENERATED_BODY()
	
private:	
	// Sets default values for this actor's properties
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	AStatue();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)

		void Pickup(); virtual void Pickup_Implementation() override;

};
