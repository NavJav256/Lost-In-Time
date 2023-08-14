// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorLight.h"

ADoorLight::ADoorLight()
{
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	RootComponent = Sphere;

	DoorLightState = EDoorLightState::EDLS_RED;
}

void ADoorLight::BeginPlay()
{
	Super::BeginPlay();

	if (TargetLever)
	{
		TargetLeverState = TargetLever->GetLeverState();
	}

	if (LightMaterialInstance)
	{
		DynamicLightMaterialInstance = UMaterialInstanceDynamic::Create(LightMaterialInstance, this);
		Sphere->SetMaterial(0, DynamicLightMaterialInstance);
		DynamicLightMaterialInstance->SetVectorParameterValue(TEXT("Color"), FVector(1, 0, 0));
	}
}

void ADoorLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetLever && TargetLever->GetLeverState() != TargetLeverState) {
		SwitchState();
		TargetLeverState = TargetLever->GetLeverState();
	}
}

void ADoorLight::SwitchState()
{
	if (DynamicLightMaterialInstance)
	{
		if (DoorLightState == EDoorLightState::EDLS_RED)
		{
			DoorLightState = EDoorLightState::EDLS_GREEN;
			DynamicLightMaterialInstance->SetVectorParameterValue(TEXT("Color"), FVector(0,1,0));
		}
		else
		{
			DoorLightState = EDoorLightState::EDLS_RED;
			DynamicLightMaterialInstance->SetVectorParameterValue(TEXT("Color"), FVector(1,0,0));
		}
	}
}

