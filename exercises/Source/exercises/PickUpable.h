// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UPickUpable : public UInterface 
{
	GENERATED_BODY()

};
class EXERCISES_API IPickUpable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Pickup();
};
