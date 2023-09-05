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

	StartCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StartCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	EndCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	EndCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RightCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RightCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	LeftCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	LeftCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	BridgeTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Bridge Timeline"));

	NumSections = 16;
	bAssembled = false;
	SideOffset = -783.f;
	PinsTopZ = 66.f;
	PinsBottomZ = -53.f;
}

void ABridge::OnConstruction(const FTransform& Transform)
{
	RightSide->ClearInstances();
	LeftSide->ClearInstances();
	RightRails->ClearInstances();
	LeftRails->ClearInstances();
	for (int32 i = 0; i < NumSections; i++)
	{
		FVector RightLocation(0, (i * 100) + 100, 0);
		FRotator RightSideRotation((bAssembled ? 0.f : 90.f), 0, 0);
		FVector LeftLocation(SideOffset, (i * 100) + 100, 0);
		FRotator LeftSideRotation((bAssembled ? 0.f : 90.f), 180.f, 0);
		FTransform RightTransform(RightSideRotation, RightLocation, FVector(1, 1, 1));
		FTransform LeftTransform(LeftSideRotation, LeftLocation, FVector(1, 1, 1));
		RightSide->AddInstance(RightTransform, false);
		LeftSide->AddInstance(LeftTransform, false);
		FTransform RightRailTransform(FRotator::ZeroRotator, RightLocation, FVector(1, 1, 1));
		FTransform LeftRailTransform(FRotator(0, 180.f, 0), LeftLocation, FVector(1, 1, 1));
		RightRails->AddInstance(RightRailTransform, false);
		LeftRails->AddInstance(LeftRailTransform, false);
	}

	FVector RightRailEndOneLocation(28.5f, 25, 140.5f);
	FVector RightRailEndTwoLocation(28.5f, ((NumSections + 1) * 100) - 25, 140.5f);
	FRotator RightRailEndTwoRotation(0, 180.f, 0);
	FTransform RightRailEndOneTransform(FRotator::ZeroRotator, RightRailEndOneLocation, FVector(1,1,1));
	FTransform RightRailEndTwoTransform(RightRailEndTwoRotation, RightRailEndTwoLocation, FVector(1,1,1));
	RightRailEndOne->SetRelativeTransform(RightRailEndOneTransform);
	RightRailEndTwo->SetRelativeTransform(RightRailEndTwoTransform);

	FVector LeftRailEndOneLocation(-808.5f, 25, 140.5f);
	FVector LeftRailEndTwoLocation(-808.5f, ((NumSections + 1) * 100) - 25, 140.5f);
	FRotator LeftRailEndTwoRotation(0, 180.f, 0);
	FTransform LeftRailEndOneTransform(FRotator::ZeroRotator, LeftRailEndOneLocation, FVector(1, 1, 1));
	FTransform LeftRailEndTwoTransform(RightRailEndTwoRotation, LeftRailEndTwoLocation, FVector(1, 1, 1));
	LeftRailEndOne->SetRelativeTransform(LeftRailEndOneTransform);
	LeftRailEndTwo->SetRelativeTransform(LeftRailEndTwoTransform);

	BridgeStart->SetRelativeLocation(FVector(SideOffset / 2, (NumSections + 1) * 100, 0));
	StartPins->SetRelativeLocation(FVector(SideOffset / 2, (NumSections + 1) * 100, bAssembled ? PinsBottomZ : PinsTopZ));
	BridgeEnd->SetRelativeLocation(FVector(SideOffset / 2, 0, 0));
	EndPins->SetRelativeLocation(FVector(SideOffset / 2, 0, bAssembled ? PinsBottomZ : PinsTopZ));

	RightCollider->SetBoxExtent(FVector(32, (NumSections + 1) * 50, 200));
	RightCollider->SetRelativeLocation(FVector(0, ((NumSections / 2) * 100) + 100, 200));
	LeftCollider->SetBoxExtent(FVector(32, (NumSections + 1) * 50, 200));
	LeftCollider->SetRelativeLocation(FVector(SideOffset, ((NumSections / 2) * 100) + 100, 200));
	StartCollider->SetBoxExtent(FVector(450, 20, 200));
	StartCollider->SetRelativeLocation(FVector(-390, (NumSections + 1) * 100, 200));
	EndCollider->SetBoxExtent(FVector(450, 20, 200));
	EndCollider->SetRelativeLocation(FVector(-390, 0, 200));
}

void ABridge::BeginPlay()
{
	Super::BeginPlay();

}

void ABridge::UpdateBridge(float BridgeRotation)
{
	FVector RightLocation(0, (BridgeIndex * 100) + 100, 0);
	FRotator RightSideRotation(BridgeRotation, 0, 0);
	FVector LeftLocation(SideOffset, (BridgeIndex * 100) + 100, 0);
	FRotator LeftSideRotation(BridgeRotation, 180.f, 0);
	FTransform RightTransform(RightSideRotation, RightLocation, FVector(1, 1, 1));
	FTransform LeftTransform(LeftSideRotation, LeftLocation, FVector(1, 1, 1));
	RightSide->UpdateInstanceTransform(BridgeIndex, RightTransform);
	LeftSide->UpdateInstanceTransform(BridgeIndex, LeftTransform);
	RightSide->MarkRenderStateDirty();
	LeftSide->MarkRenderStateDirty();
}

void ABridge::BridgeComplete()
{
	BridgeIndex++;
	if (BridgeIndex < NumSections)
	{
		if (bAssembled)
		{
			BridgeTimeline->PlayFromStart();
		}
		else
		{
			BridgeTimeline->ReverseFromEnd();
		}
	}
	else
	{
		if (bAssembled)
		{
			StartPins->SetRelativeLocation(FVector(SideOffset / 2, (NumSections + 1) * 100, PinsBottomZ));
			StartCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
			StartCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Ignore);
		}
	}
}

void ABridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABridge::Activate()
{
	BridgeIndex = 0;
	bAssembled = true;
	EndPins->SetRelativeLocation(FVector(SideOffset / 2, 0, PinsBottomZ));
	EndCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	EndCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Ignore);
	BridgeTrack.BindDynamic(this, &ABridge::UpdateBridge);
	if (BridgeTimeline && BridgeCurve)
	{
		BridgeTimeline->AddInterpFloat(BridgeCurve, BridgeTrack);
		BridgeTimeline->SetTimelineFinishedFunc(FOnTimelineEventStatic::CreateUObject(this, &ABridge::BridgeComplete));
		BridgeTimeline->SetPlayRate(2.f);
		BridgeTimeline->Play();	
	}
}

void ABridge::Deactivate()
{
	BridgeIndex = 0;
	bAssembled = false;
	StartPins->SetRelativeLocation(FVector(SideOffset / 2, (NumSections + 1) * 100, PinsTopZ));
	EndPins->SetRelativeLocation(FVector(SideOffset / 2, 0, PinsTopZ));
	StartCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	StartCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
	EndCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	EndCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
	BridgeTrack.BindDynamic(this, &ABridge::UpdateBridge);
	if (BridgeTimeline && BridgeCurve)
	{
		BridgeTimeline->AddInterpFloat(BridgeCurve, BridgeTrack);
		BridgeTimeline->SetTimelineFinishedFunc(FOnTimelineEventStatic::CreateUObject(this, &ABridge::BridgeComplete));
		BridgeTimeline->SetPlayRate(10.f);
		BridgeTimeline->ReverseFromEnd();
	}
}
