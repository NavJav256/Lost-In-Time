// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lost_In_Time/Interfaces/Dragable.h"
#include "DragableObject.generated.h"

UCLASS()
class LOST_IN_TIME_API ADragableObject : public AActor, public IDragable
{
	GENERATED_BODY()
	
public:

	ADragableObject();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

};
