// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeButton.h"

ACubeButton::ACubeButton()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Button"));
	Button->SetupAttachment(RootComponent);

	ButtonTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Button Timeline"));

	bPressed = false;
}


void ACubeButton::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACubeButton::Interact()
{
	ButtonTrack.BindDynamic(this, &ACubeButton::UpdateButton);
	if (ButtonTimeline && ButtonCurve)
	{
		ButtonTimeline->AddInterpFloat(ButtonCurve, ButtonTrack);
		bPressed = !bPressed;
		if (bPressed)
		{
			ButtonTimeline->Play();
		}
		else
		{
			ButtonTimeline->ReverseFromEnd();
		}
	}
}

void ACubeButton::UpdateButton(float ButtonPosition)
{
	FVector Location = Button->GetRelativeLocation();
	Location.Z = ButtonPosition;

	Button->SetRelativeLocation(Location);
}