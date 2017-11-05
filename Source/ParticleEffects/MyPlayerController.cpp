// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"

AMyPlayerController::AMyPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	// Our root component will be a sphere that reacts to physics
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(10.0f);

	UClass* CamerasRigChildActor_Class = StaticLoadClass(UObject::StaticClass(), NULL, TEXT("/Game/BatExperiments/Blueprints/BP_CamerasRig.BP_CamerasRig_C"), NULL, LOAD_None, NULL);
	if (CamerasRigChildActor_Class) {
		CamerasRigChildActorComponent = CreateDefaultSubobject<UChildActorComponent>("CamerasRigChildActorComponent");
		CamerasRigChildActorComponent->SetupAttachment(RootComponent);
		CamerasRigChildActorComponent->SetChildActorClass(CamerasRigChildActor_Class);
		CamerasRigChildActorComponent->CreateChildActor();
	}
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT(">>AMyPlayerController::BeginPlay()"));
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

