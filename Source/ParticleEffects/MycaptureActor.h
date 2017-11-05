// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MycaptureActor.generated.h"

class USceneCaptureComponent2D;
class APlayerController;


UCLASS()
class PARTICLEEFFECTS_API AMycaptureActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMycaptureActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BatGames")
	USceneCaptureComponent2D* SceneCaptureComponent2D;

	APlayerController* PlayerController;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
