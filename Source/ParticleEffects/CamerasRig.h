// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CamerasRig.generated.h"

class AMycaptureActor;

UCLASS()
class PARTICLEEFFECTS_API ACamerasRig : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACamerasRig();

	UPROPERTY(EditDefaultsOnly, Category = "BatGames")
	TSubclassOf<AMycaptureActor> AMycaptureActorBP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
