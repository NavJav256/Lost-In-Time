// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnergyCube.generated.h"

UENUM(BlueprintType)
enum class ECubeState : uint8
{
	ECS_IDLE UMETA(DisplayName = "Idle"),
	ECS_CHARGE UMETA(DisplayName = "Charging"),
	ECS_DISCHARGE UMETA(DisplayName = "Discharging"),

	ECS_MAX UMETA(DisplayName = "Default Max")
};

UCLASS()
class LOST_IN_TIME_API AEnergyCube : public AActor
{
	GENERATED_BODY()
	
public:

	AEnergyCube();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	void Charge(float DeltaTime);

	void Discharge(float DeltaTime);

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* EnergyCube;

	UPROPERTY(VisibleAnywhere)
	ECubeState CubeState;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* VoltageMaterialInstance;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicVoltageMaterialInstance;

	UPROPERTY(VisibleAnywhere)
	float Voltage;

public:

	FORCEINLINE void ChargeCube() { CubeState = ECubeState::ECS_CHARGE; }
	FORCEINLINE void DischargeCube() { CubeState = ECubeState::ECS_DISCHARGE; }
	FORCEINLINE void StopCube() { CubeState = ECubeState::ECS_IDLE; }

	FORCEINLINE float GetVoltage() { return Voltage; }

};
