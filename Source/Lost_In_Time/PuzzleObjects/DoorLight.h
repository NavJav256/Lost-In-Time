// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lever.h"
#include "DoorLight.generated.h"

UENUM(BlueprintType)
enum class EDoorLightState : uint8
{
	EDLS_RED UMETA(DisplayName = "Red"),
	EDLS_GREEN UMETA(DisplayName = "Green"),

	EDLS_MAX UMETA(DisplayName = "Default Max")
};

UCLASS()
class LOST_IN_TIME_API ADoorLight : public AActor
{
	GENERATED_BODY()
	
public:

	ADoorLight();

	virtual void Tick(float DeltaTime) override;

	void SwitchState();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Sphere;

	UPROPERTY(VisibleAnywhere)
	EDoorLightState DoorLightState;

	UPROPERTY(EditAnywhere)
	ALever* TargetLever;

	ELeverState TargetLeverState;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicLightMaterialInstance;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* LightMaterialInstance;

};
