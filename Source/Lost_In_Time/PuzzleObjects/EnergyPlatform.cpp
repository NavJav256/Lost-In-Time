// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyPlatform.h"
#include "Components/BoxComponent.h"

AEnergyPlatform::AEnergyPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = PlatformMesh;

	OverlapRegion = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Region"));
	OverlapRegion->SetupAttachment(PlatformMesh);

	bCharge = true;
}

void AEnergyPlatform::OnConstruction(const FTransform& Transform)
{
	if (bCharge)
	{
		PlatformMesh->SetStaticMesh(PlatformMeshes[0]);
	}
	else
	{
		PlatformMesh->SetStaticMesh(PlatformMeshes[1]);
	}
}

void AEnergyPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	OverlapRegion->OnComponentBeginOverlap.AddDynamic(this, &AEnergyPlatform::OnOverlapBegin);
	OverlapRegion->OnComponentEndOverlap.AddDynamic(this, &AEnergyPlatform::OnOverlapEnd);
}

void AEnergyPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Cube = Cast<AEnergyCube>(OtherActor);
	if (Cube)
	{
		if (bCharge)
		{
			Cube->ChargeCube();
		}
		else
		{
			Cube->DischargeCube();
		}
	}
}

void AEnergyPlatform::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cube == OtherActor)
	{
		Cube->StopCube();
		Cube = nullptr;
	}
}
