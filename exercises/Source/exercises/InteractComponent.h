// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXERCISES_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	
	FCollisionShape TraceSphere;

public:
	UInteractorComponent();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Radius = 500.f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
