// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class ACamerasRig;
class UChildActorComponent;
/**
 * 
 */
UCLASS()
class PARTICLEEFFECTS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	AMyPlayerController();
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	ACamerasRig* CamerasRig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BatGames")
	UChildActorComponent* CamerasRigChildActorComponent;

private:
	
	
};
