// Fill out your copyright notice in the Description page of Project Settings.

#include "CamerasRig.h"
#include "MycaptureActor.h"
#include "Components/SphereComponent.h"


// Sets default values
ACamerasRig::ACamerasRig()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Our root component will be a sphere that reacts to physics
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(10.0f);

}

// Called when the game starts or when spawned
void ACamerasRig::BeginPlay()
{
	Super::BeginPlay();

	if (AMycaptureActorBP)
	{
		GetWorld()->SpawnActor<AMycaptureActor>(AMycaptureActorBP);
	}

	UE_LOG(LogTemp, Warning, TEXT("ACamerasRig::BeginPlay()"));
}

// Called every frame
void ACamerasRig::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

