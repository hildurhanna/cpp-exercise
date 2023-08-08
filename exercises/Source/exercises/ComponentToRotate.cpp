// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentToRotate.h"

// Sets default values for this component's properties
UComponentToRotate::UComponentToRotate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UComponentToRotate::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComponentToRotate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	auto Owner = GetOwner();
	auto Rotate = FRotator(0, rotationSpeed * DeltaTime, 0);
	Owner->AddActorLocalRotation(Rotate);

	
}

