// Fill out your copyright notice in the Description page of Project Settings.


#include "WallButton.h"

AWallButton::AWallButton()
{
	PrimaryActorTick.bCanEverTick = false;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	RootComponent = ButtonMesh;
}

void AWallButton::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWallButton::PressButton()
{
	if (bPressed)
	{
		
	}
	else
	{

	}
	bPressed = !bPressed;
}
