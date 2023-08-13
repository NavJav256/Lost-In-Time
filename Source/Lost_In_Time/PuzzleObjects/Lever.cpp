// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"
#include "Components/SphereComponent.h"
#include "Lost_In_Time/Character/LITCharacter.h"
#include "Lost_In_Time/PuzzleObjects/Door.h"

ALever::ALever()
{
	PrimaryActorTick.bCanEverTick = false;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever Base"));
	RootComponent = Base;

	Handle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever Handle"));
	Handle->SetupAttachment(RootComponent);

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	AreaSphere->SetupAttachment(RootComponent);

	HandleTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Handle Timeline Component"));

	LeverState = ELeverState::ELS_OFF;
}

void ALever::BeginPlay()
{
	Super::BeginPlay();
	
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AreaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &ALever::OnSphereOverlap);
	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &ALever::OnSphereEndOverlap);
}

void ALever::OnSphereOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ALITCharacter* LITCharacter = Cast<ALITCharacter>(OtherActor);
	if (LITCharacter)
	{
		LITCharacter->SetInteractLever(this);
	}
}

void ALever::OnSphereEndOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ALITCharacter* LITCharacter = Cast<ALITCharacter>(OtherActor);
	if (LITCharacter)
	{
		LITCharacter->SetInteractLever(nullptr);
	}
}

void ALever::UpdateHandle(float HandleRotation)
{
	FRotator HandleRot = Handle->GetRelativeRotation();
	HandleRot.Roll = HandleRotation;
	Handle->SetRelativeRotation(HandleRot);
}

void ALever::Interact()
{
	HandleTrack.BindDynamic(this, &ALever::UpdateHandle);
	if (HandleTimeline && HandleCurve)
	{
		HandleTimeline->AddInterpFloat(HandleCurve, HandleTrack);
		if (LeverState == ELeverState::ELS_OFF)
		{
			LeverState = ELeverState::ELS_ON;
			HandleTimeline->Play();
		}
		else
		{
			LeverState = ELeverState::ELS_OFF;
			HandleTimeline->ReverseFromEnd();
		}
	}
}

