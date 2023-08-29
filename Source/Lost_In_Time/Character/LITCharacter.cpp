// Fill out your copyright notice in the Description page of Project Settings.


#include "LITCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Lost_In_Time/PlayerController/LITPlayerController.h"
#include "Lost_In_Time/Interfaces/Dragable.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "Lost_In_Time/HUD/LITHUD.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "DrawDebugHelpers.h"

ALITCharacter::ALITCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(GetMesh(), FName("Head"));
	FollowCamera->bUsePawnControlRotation = true;

	GetMesh()->HideBoneByName(FName("Head"), EPhysBodyOp::PBO_None);

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("Physics Handle"));
}

void ALITCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (const ULocalPlayer* Player = (GEngine && GetWorld()) ? GEngine->GetFirstGamePlayer(GetWorld()) : nullptr)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Player))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void ALITCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitRes;
	TraceUnderCrosshair(HitRes);

	DragLoop();
}

void ALITCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ALITCharacter::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ALITCharacter::Look);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ALITCharacter::Interact);

		EnhancedInputComponent->BindAction(DragAction, ETriggerEvent::Triggered, this, &ALITCharacter::StartDrag);
		EnhancedInputComponent->BindAction(DragAction, ETriggerEvent::Completed, this, &ALITCharacter::StopDrag);
		
	}
}

void ALITCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ALITCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void ALITCharacter::Interact()
{
	if (LookAtActor)
	{
		IInteractable* Interactable = Cast<IInteractable>(LookAtActor);
		if (Interactable)
		{
			Interactable->Interact();
		}
	}
}

void ALITCharacter::StartDrag()
{
	if (DragActor)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(DragActor, TEXT("None"), DragActor->GetComponentLocation(), DragActor->GetComponentRotation());
		bGrabbing = true;
	}
}

void ALITCharacter::DragLoop()
{
	if (bGrabbing)
	{
		PhysicsHandle->SetTargetLocation(FollowCamera->GetComponentLocation() + GetActorForwardVector() * 250);
	}
}

void ALITCharacter::StopDrag()
{
	if (bGrabbing)
	{
		PhysicsHandle->ReleaseComponent();
		bGrabbing = false;
	}
}

void ALITCharacter::TraceUnderCrosshair(FHitResult& HitResult)
{
	HUD = HUD == nullptr ? Cast<ALITHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD()) : HUD;
	
	FVector2D ViewportSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	FVector2D CrosshairLocation(ViewportSize.X / 2, ViewportSize.Y / 2);
	FVector CrosshairWorldPosition;
	FVector CrosshairWorldDirection;

	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(
		UGameplayStatics::GetPlayerController(this, 0),
		CrosshairLocation,
		CrosshairWorldPosition,
		CrosshairWorldDirection
	);

	if (bScreenToWorld)
	{
		FVector Start = CrosshairWorldPosition;
		float DistanceToCharacter = (GetActorLocation() - Start).Size();
		Start += CrosshairWorldDirection * (DistanceToCharacter - 80.f);
		FVector End = Start + CrosshairWorldDirection * 200.f;
		GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);
		//DrawDebugLine(GetWorld(), Start, End, FColor::Cyan);

		if (HitResult.GetActor())
		{
			LookAtActor = HitResult.GetActor();
			if (LookAtActor->Implements<UDragable>())
			{
				DragActor = HitResult.GetComponent();
				HUD->SetCrosshairColor(FLinearColor::Red);
			}
			else if (LookAtActor->Implements<UInteractable>())
			{
				HUD->SetCrosshairColor(FLinearColor::Red);
			}
			else
			{
				DragActor = nullptr;
				HUD->SetCrosshairColor(FLinearColor::White);
			}
		}
	}
}


