// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "LITCharacter.generated.h"

UCLASS()
class LOST_IN_TIME_API ALITCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ALITCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* DragAction;

protected:

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Interact();

	void StartDrag();

	void DragLoop();

	void StopDrag();

	void TraceUnderCrosshair(FHitResult& HitResult);

private:

	UPROPERTY()
	class ALITHUD* HUD;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere)
	class ALever* InteractLever;

	UPROPERTY(VisibleAnywhere)
	class UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY(EditAnywhere)
	UTexture2D* CrosshairTexture;

	bool bGrabbing;

	UPrimitiveComponent* DragActor;

public:

	void SetInteractLever(ALever* Lever);

};
