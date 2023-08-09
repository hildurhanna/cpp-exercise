// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"
#include "PickUpable.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;
	TraceSphere = FCollisionShape::MakeSphere(Radius);

	// ...
}


void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const AActor* Owner = GetOwner();

	TArray<FOverlapResult> PossibleActors;

	auto bBlockingHit = GetWorld()->OverlapMultiByChannel(PossibleActors, Owner->GetActorLocation(), FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1, TraceSphere);
	
	for (int i = 0; i < PossibleActors.Num(); i++)
	{
		AActor* ActorReference = PossibleActors[i].GetActor();
		if (ActorReference->Implements<UPickUpable>()))
		{

		}
	}
}


