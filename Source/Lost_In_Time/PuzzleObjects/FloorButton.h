// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorButton.generated.h"

UENUM(BlueprintType)
enum class EFloorButtonSize : uint8
{
	EFBS_1_1 UMETA(DisplayName = "1 x 1"),
	EFBS_2_1 UMETA(DisplayName = "2 x 1"),
	EFBS_3_1 UMETA(DisplayName = "3 x 1"),
	EFBS_2_2 UMETA(DisplayName = "2 x 2"),
	EFBS_3_2 UMETA(DisplayName = "3 x 2"),

	EFBS_MAX UMETA(DisplayName = "Default Max")
};

UCLASS()
class LOST_IN_TIME_API AFloorButton : public AActor
{
	GENERATED_BODY()
	
public:

	AFloorButton();

	virtual void OnConstruction(const FTransform& Transform) override;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	EFloorButtonSize ButtonSize;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ButtonMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* OverlapVolume;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionArea;

	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> Meshes;


public:

	FORCEINLINE UBoxComponent* GetOverlapVolume() { return OverlapVolume; }

};
