// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorButton.h"
#include "Components/BoxComponent.h"
#include "Lost_In_Time/PuzzleObjects/LaserWall.h"

AFloorButton::AFloorButton()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button Mesh"));
	ButtonMesh->SetupAttachment(RootComponent);

	CollisionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	CollisionArea->SetupAttachment(RootComponent);

	OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Volume"));
	OverlapVolume->SetupAttachment(RootComponent);
}

void AFloorButton::OnConstruction(const FTransform& Transform)
{
	switch (ButtonSize)
	{
		case EFloorButtonSize::EFBS_1_1:
			ButtonMesh->SetStaticMesh(Meshes[0]);
			CollisionArea->SetBoxExtent(FVector(50, 50, 5));
			OverlapVolume->SetBoxExtent(FVector(40, 40, 5));
			break;
		case EFloorButtonSize::EFBS_2_1:
			ButtonMesh->SetStaticMesh(Meshes[1]);
			CollisionArea->SetBoxExtent(FVector(100, 50, 5));
			OverlapVolume->SetBoxExtent(FVector(90, 40, 5));
			break;
		case EFloorButtonSize::EFBS_3_1:
			ButtonMesh->SetStaticMesh(Meshes[2]);
			CollisionArea->SetBoxExtent(FVector(150, 50, 5));
			OverlapVolume->SetBoxExtent(FVector(140, 40, 5));
			break;
		case EFloorButtonSize::EFBS_2_2:
			ButtonMesh->SetStaticMesh(Meshes[3]);
			CollisionArea->SetBoxExtent(FVector(100, 100, 5));
			OverlapVolume->SetBoxExtent(FVector(90, 90, 5));
			break;
		case EFloorButtonSize::EFBS_3_2:
			ButtonMesh->SetStaticMesh(Meshes[4]);
			CollisionArea->SetBoxExtent(FVector(150, 100, 5));
			OverlapVolume->SetBoxExtent(FVector(140, 90, 5));
			break;
	}
}

void AFloorButton::BeginPlay()
{
	Super::BeginPlay();
	
	OverlapVolume->OnComponentBeginOverlap.AddDynamic(this, &AFloorButton::OnOverlap);
	OverlapVolume->OnComponentEndOverlap.AddDynamic(this, &AFloorButton::OnOverlapEnd);
}

void AFloorButton::OnOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (TargetLaserWall)
	{
		if (bActivatesLasers)
		{
			TargetLaserWall->Activate();
		}
		else
		{
			TargetLaserWall->Deactivate();
		}
	}
}

void AFloorButton::OnOverlapEnd(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}



