// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftButton.h"
#include "Lost_In_Time/PuzzleObjects/Lift.h"

ALiftButton::ALiftButton()
{
	PrimaryActorTick.bCanEverTick = false;

	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	RootComponent = Button;
}

void ALiftButton::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALiftButton::Interact()
{
	if (TargetLift)
	{
		TargetLift->ActivateLift();
	}
}