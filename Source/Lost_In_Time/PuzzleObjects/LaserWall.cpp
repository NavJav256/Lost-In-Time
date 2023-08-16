// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserWall.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/BoxComponent.h"

ALaserWall::ALaserWall()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	Lasers = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Lasers"));
	Lasers->SetupAttachment(RootComponent);

	LaserTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Laser Timeline"));

	BlockArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Block Area"));
	BlockArea->SetupAttachment(RootComponent);
	BlockArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BlockArea->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BlockArea->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

	bActive = true;
}

void ALaserWall::OnConstruction(const FTransform& Transform)
{
	Lasers->ClearInstances();

	for (int32 i = 0; i < NumRays - 1; i++)
	{
		FVector LaserWorldLocation = Lasers->GetComponentLocation();
		FVector Location = i * RayStep * GetActorForwardVector() + LaserWorldLocation;
		FRotator Rotation = GetActorRotation();
		float Scale = RayLength / 100;
		FTransform LaserTransform(Rotation, Location, FVector(1, Scale, 1));
		Lasers->AddInstance(LaserTransform, true);
	}

	FVector BoxExtent;
	BoxExtent.X = (((NumRays - 1) * RayStep) + OverlapWidth) / 2;
	BoxExtent.Y = RayLength / 2;
	BoxExtent.Z = OverlapHeight;
	BlockArea->SetBoxExtent(BoxExtent, true);

	FVector BoxLocation;
	BoxLocation.X = BoxExtent.X - (OverlapWidth / 2);
	BoxLocation.Y = RayLength / 2;
	BoxLocation.Z = 0;
	BlockArea->SetRelativeLocation(BoxLocation);
}

void ALaserWall::BeginPlay()
{
	Super::BeginPlay();
	
	if (LaserMaterialInstance)
	{
		DynamicLaserMaterialInstance = UMaterialInstanceDynamic::Create(LaserMaterialInstance, this);
		Lasers->SetMaterial(0, DynamicLaserMaterialInstance);
		DynamicLaserMaterialInstance->SetScalarParameterValue(TEXT("Opacity"), 1.f);
	}
}

void ALaserWall::UpdateLasers(float LaserOpacity)
{
	DynamicLaserMaterialInstance->SetScalarParameterValue(TEXT("Opacity"), LaserOpacity);
}

void ALaserWall::Activate()
{
	if (!bActive)
	{
		bActive = true;
		BlockArea->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
		LaserTrack.BindDynamic(this, &ALaserWall::UpdateLasers);
		if (LaserTimeline && LaserCurve)
		{
			LaserTimeline->AddInterpFloat(LaserCurve, LaserTrack);
			LaserTimeline->Play();
		}
	}
}

void ALaserWall::Deactivate()
{
	if (bActive)
	{
		bActive = false;
		BlockArea->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
		LaserTrack.BindDynamic(this, &ALaserWall::UpdateLasers);
		if (LaserTimeline && LaserCurve)
		{
			LaserTimeline->AddInterpFloat(LaserCurve, LaserTrack);
			LaserTimeline->ReverseFromEnd();
		}
	}
}
