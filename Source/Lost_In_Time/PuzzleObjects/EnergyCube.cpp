// Fill out your copyright notice in the Description page of Project Settings.

#include "EnergyCube.h"

AEnergyCube::AEnergyCube()
{
	PrimaryActorTick.bCanEverTick = true;

	EnergyCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Energy Cube"));
	RootComponent = EnergyCube;

	CubeState = ECubeState::ECS_IDLE;
	Voltage = 0;
}

void AEnergyCube::BeginPlay()
{
	Super::BeginPlay();

	if (VoltageMaterialInstance)
	{
		DynamicVoltageMaterialInstance = UMaterialInstanceDynamic::Create(VoltageMaterialInstance, this);
		EnergyCube->SetMaterial(1, DynamicVoltageMaterialInstance);
		DynamicVoltageMaterialInstance->SetScalarParameterValue(TEXT("Voltage"), 0.f);
	}
}

void AEnergyCube::Tick(float DeltaTime)
{
	switch (CubeState)
	{
		case ECubeState::ECS_CHARGE:
			Charge(DeltaTime);
			break;
		case ECubeState::ECS_DISCHARGE:
			Discharge(DeltaTime);
			break;
		case ECubeState::ECS_IDLE:
			return;
	}
}

void AEnergyCube::Charge(float DeltaTime)
{
	if (Voltage <= 1.f)
	{
		Voltage += DeltaTime;
	}
	else
	{
		Voltage = 1.f;
	}
	DynamicVoltageMaterialInstance->SetScalarParameterValue(TEXT("Voltage"), Voltage);
}

void AEnergyCube::Discharge(float DeltaTime)
{
	if (Voltage >= 0)
	{
		Voltage -= DeltaTime;
	}
	else
	{
		Voltage = 0;
	}
	DynamicVoltageMaterialInstance->SetScalarParameterValue(TEXT("Voltage"), Voltage);
}