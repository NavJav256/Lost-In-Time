// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lost_In_Time/PuzzleObjects/EnergyCube.h"
#include "EnergyCubeTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnlockEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLockEvent);

UCLASS()
class LOST_IN_TIME_API AEnergyCubeTrigger : public AActor
{
	GENERATED_BODY()
	
public:

	AEnergyCubeTrigger();

	virtual void OnConstruction(const FTransform& Transform) override;

	FOnUnlockEvent OnUnlockEvent;
	FOnLockEvent OnLockEvent;

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:


	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Platform;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Indicator;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere)
	AEnergyCube* Cube;

	UPROPERTY(EditAnywhere)
	bool bNeedsPower;

	UPROPERTY(VisibleAnywhere)
	bool bLocked;

};
