// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FogWall.generated.h"

UCLASS()
class LOST_IN_TIME_API AFogWall : public AActor
{
	GENERATED_BODY()
	
public:

	AFogWall();

	void ShowFog();

	void ClearFog();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FogMesh;

	bool bVisible;
};
