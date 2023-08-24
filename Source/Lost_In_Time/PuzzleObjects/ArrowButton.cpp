// Fill out your copyright notice in the Description page of Project Settings.


#include "ArrowButton.h"
#include "Lost_In_Time/PuzzleObjects/Counter.h"

AArrowButton::AArrowButton()
{
	PrimaryActorTick.bCanEverTick = false;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button Mesh"));
	RootComponent = ButtonMesh;

}

void AArrowButton::Interact()
{
	switch (ArrowDirection)
	{
		case EArrowDirection::EAD_UP:
			if (TargetCounter)
			{
				TargetCounter->Increment();
			}
			break;
		case EArrowDirection::EAD_DOWN:
			if (TargetCounter)
			{
				TargetCounter->Decrement();
			}
			break;
	}
}

void AArrowButton::BeginPlay()
{
	Super::BeginPlay();
	
}

