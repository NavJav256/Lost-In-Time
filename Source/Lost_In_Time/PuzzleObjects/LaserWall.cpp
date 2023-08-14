// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserWall.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/BoxComponent.h"

ALaserWall::ALaserWall()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	Lasers = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Lasers"));
	Lasers->SetupAttachment(RootComponent);

	BlockArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Block Area"));
	BlockArea->SetupAttachment(RootComponent);
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
	
}

void ALaserWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
