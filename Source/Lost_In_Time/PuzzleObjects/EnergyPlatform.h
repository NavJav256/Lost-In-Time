// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lost_In_Time/PuzzleObjects/EnergyCube.h"
#include "EnergyPlatform.generated.h"

UCLASS()
class LOST_IN_TIME_API AEnergyPlatform : public AActor
{
	GENERATED_BODY()
	
public:

	AEnergyPlatform();

	virtual void OnConstruction(const FTransform& Transform) override;

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> PlatformMeshes;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* OverlapRegion;

	UPROPERTY(VisibleAnywhere)
	AEnergyCube* Cube;

	UPROPERTY(EditAnywhere)
	bool bCharge;

};
