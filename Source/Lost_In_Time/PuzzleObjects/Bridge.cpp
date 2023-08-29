// Fill out your copyright notice in the Description page of Project Settings.


#include "Bridge.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/BoxComponent.h"

ABridge::ABridge()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	BridgeStart = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bridge Start"));
	BridgeStart->SetupAttachment(RootComponent);

	BridgeEnd = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bridge End"));
	BridgeEnd->SetupAttachment(RootComponent);

	StartPins = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bridge Start Pins"));
	StartPins->SetupAttachment(RootComponent);

	EndPins = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bridge End Pins"));
	EndPins->SetupAttachment(RootComponent);

	RightRails = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Right Railings"));
	RightRails->SetupAttachment(RootComponent);

	RightRailEndOne = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right End Railing Start"));
	RightRailEndOne->SetupAttachment(RootComponent);

	RightRailEndTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right End Railing End"));
	RightRailEndTwo->SetupAttachment(RootComponent);

	LeftRails = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Left Railings"));
	LeftRails->SetupAttachment(RootComponent);

	LeftRailEndOne = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left End Railing Start"));
	LeftRailEndOne->SetupAttachment(RootComponent);

	LeftRailEndTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left End Railing End"));
	LeftRailEndTwo->SetupAttachment(RootComponent);

	RightSide = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Right Bridge Platform"));
	RightSide->SetupAttachment(RootComponent);

	LeftSide = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Left Bridge Platform"));
	LeftSide->SetupAttachment(RootComponent);

	StartCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Bridge Start Collider"));
	StartCollider->SetupAttachment(RootComponent);

	EndCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Bridge End Collider"));
	EndCollider->SetupAttachment(RootComponent);

	RightCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Bridge Right Collider"));
	RightCollider->SetupAttachment(RootComponent);

	LeftCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Bridge Left Collider"));
	LeftCollider->SetupAttachment(RootComponent);
}

void ABridge::OnConstruction(const FTransform& Transform)
{

}

void ABridge::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABridge::Activate()
{

}

void ABridge::Deactivate()
{

}
