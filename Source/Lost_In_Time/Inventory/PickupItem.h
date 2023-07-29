// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "Lost_In_Time/Structs/ItemDetails.h"
#include "PickupItem.generated.h"

UCLASS()
class LOST_IN_TIME_API APickupItem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	
	APickupItem();

	void ShowPickupWidget(bool bShowWidget);

	virtual void Interact();


protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


private:

	UPROPERTY(VisibleAnywhere, Category = "Pickup Properties")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Pickup Properties")
	class USphereComponent* AreaSphere;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	class UWidgetComponent* PickupWidget;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	class USoundCue* PickupCue;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	FItemDetails ItemDetails;

public:

	FORCEINLINE USoundCue* GetPickupCue() { return PickupCue; }

};
