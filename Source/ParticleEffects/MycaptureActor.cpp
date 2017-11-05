// Fill out your copyright notice in the Description page of Project Settings.

#include "MycaptureActor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Materials/Material.h"

#include "Runtime/Engine/Classes/Components/SceneCaptureComponent2D.h"
#include "Runtime/Engine/Classes/Engine/CanvasRenderTarget2D.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

// Sets default values
AMycaptureActor::AMycaptureActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* CameraVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraVisual"));
	RootComponent = CameraVisual;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CameraVisualAsset(TEXT("StaticMesh'/Engine/EditorMeshes/MatineeCam_SM.MatineeCam_SM'"));
	if (CameraVisualAsset.Succeeded())
	{
		CameraVisual->SetStaticMesh(CameraVisualAsset.Object);

		static ConstructorHelpers::FObjectFinder<UMaterial> CameraMatAsset(TEXT("Material'/Engine/EditorMaterials/MatineeCam_mat.MatineeCam_mat'"));
		if (CameraMatAsset.Succeeded())
		{
			CameraVisual->SetMaterial(0, CameraMatAsset.Object);
		}
	}


	// Add Scene capture
	SceneCaptureComponent2D = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent2D"));
	SceneCaptureComponent2D->bCaptureEveryFrame = true;
	SceneCaptureComponent2D->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	SceneCaptureComponent2D->CompositeMode = ESceneCaptureCompositeMode::SCCM_Overwrite;
	SceneCaptureComponent2D->DetailMode = EDetailMode::DM_High;
	SceneCaptureComponent2D->PostProcessBlendWeight = 1.0f;

	static ConstructorHelpers::FObjectFinder<UCanvasRenderTarget2D> CanvasRenderTargetAsset(TEXT("CanvasRenderTarget2D'/Game/BatExperiments/SceneCapture/SceneRenderTarget.SceneRenderTarget'"));
	if (CanvasRenderTargetAsset.Succeeded())
	{
		SceneCaptureComponent2D->TextureTarget = CanvasRenderTargetAsset.Object;
	}

	SceneCaptureComponent2D->SetupAttachment(RootComponent);

	//// Flags
	//{
	//	FEngineShowFlagsSetting AmbientCubemap;
	//	AmbientCubemap.Enabled = true;
	//	AmbientCubemap.ShowFlagName = "AmbientCubemap";

	//	FEngineShowFlagsSetting AmbientOcclusion;
	//	AmbientOcclusion.Enabled = true;
	//	AmbientOcclusion.ShowFlagName = "AmbientOcclusion";

	//	FEngineShowFlagsSetting AntiAliasing;
	//	AntiAliasing.Enabled = true;
	//	AntiAliasing.ShowFlagName = "AntiAliasing";

	//	FEngineShowFlagsSetting PostProcessing;
	//	PostProcessing.Enabled = true;
	//	PostProcessing.ShowFlagName = "PostProcessing";

	//	FEngineShowFlagsSetting PostProcessMaterial;
	//	PostProcessMaterial.Enabled = true;
	//	PostProcessMaterial.ShowFlagName = "PostProcessMaterial";

	//	FEngineShowFlagsSetting TemporalAA;
	//	TemporalAA.Enabled = true;
	//	TemporalAA.ShowFlagName = "TemporalAA";


	//	TArray<FEngineShowFlagsSetting> EngineShowFlagsSetting =
	//	{
	//		AmbientCubemap, AmbientOcclusion, AntiAliasing,
	//		PostProcessing, PostProcessMaterial, TemporalAA

	//	};
	//	SceneCaptureComponent2D->ShowFlagSettings = EngineShowFlagsSetting;

	//	FEngineShowFlags EngineShowFlags(EShowFlagInitMode::ESFIM_Game);
	//	EngineShowFlags.EnableAdvancedFeatures();
	//	SceneCaptureComponent2D->ShowFlags = EngineShowFlags;
	//}

}

// Called when the game starts or when spawned
void AMycaptureActor::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	UE_LOG(LogTemp, Warning, TEXT(">>AMycaptureActor::BeginPlay()"));

	
}

// Called every frame
void AMycaptureActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerController)
	{
		FVector PlayerLocation;
		FRotator PlayerRotation;

		PlayerController->GetPlayerViewPoint(PlayerLocation, PlayerRotation);

		SceneCaptureComponent2D->SetWorldLocationAndRotation(PlayerLocation, PlayerRotation);
	}
}

