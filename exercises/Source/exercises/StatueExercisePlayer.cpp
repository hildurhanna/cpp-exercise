// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueExercisePlayer.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AStatueExercisePlayer::AStatueExercisePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	CapsuleComponent->InitCapsuleSize(55.f, 96.f);
	CapsuleComponent->SetSimulatePhysics(true);

	constexpr float InertiaTensorScale = 10000.f;
	CapsuleComponent->BodyInstance.InertiaTensorScale = FVector(InertiaTensorScale, InertiaTensorScale, InertiaTensorScale);

	SetRootComponent(CapsuleComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CapsuleComponent);
	CameraComponent->SetRelativeLocation(FVector(0, 0, 100.f));

}

void AStatueExercisePlayer::Look(const FVector2D AxisInput)
{
	//Rotate on the horizontal axis
	AddActorLocalRotation(FRotator(0.f, AxisInput.X, 0.f));

	//Clamp vertical axis
	CurrentLookRotation += AxisInput.Y;
	CurrentLookRotation = FMath::ClampAngle(CurrentLookRotation, -90.f, 90.f);

	CameraComponent->SetWorldRotation(FRotator(CurrentLookRotation, GetActorRotation().Yaw, 0.f));

}

void AStatueExercisePlayer::Move(const FVector2D AxisInput) 
{
	auto moveVector = FVector(AxisInput.Y, -AxisInput.X, 0.f);

	auto transformedVector = UKismetMathLibrary::TransformDirection(GetActorTransform(), moveVector);

	auto deltaTime = GetWorld()->GetDeltaSeconds();

	transformedVector *= moveSpeed;

	SetActorLocation(
		GetActorLocation() +
		moveVector * deltaTime
	);
	
}
