// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bridge.generated.h"

UCLASS()
class LOST_IN_TIME_API ABridge : public AActor
{
	GENERATED_BODY()
	
public:

	ABridge();

	virtual void OnConstruction(const FTransform& Transform) override;

	void Activate();

	void Deactivate();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BridgeStart;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BridgeEnd;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StartPins;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* EndPins;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* RightRails;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RightRailEndOne;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RightRailEndTwo;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* LeftRails;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeftRailEndOne;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeftRailEndTwo;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* RightSide;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* LeftSide;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* StartCollider;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* EndCollider;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* RightCollider;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* LeftCollider;

	UPROPERTY(EditAnywhere, Category = "Bridge Properties")
	float SideOffset;

	UPROPERTY(EditAnywhere, Category = "Bridge Properties")
	int32 NumSections;

	UPROPERTY(EditAnywhere, Category = "Bridge Properties")
	bool bAssembled;

	UPROPERTY(EditAnywhere, Category = "Bridge Properties")
	float PinsTopZ;

	UPROPERTY(EditAnywhere, Category = "Bridge Properties")
	float PinsBottomZ;
};
