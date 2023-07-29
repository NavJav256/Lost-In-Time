// Fill out your copyright notice in the Description page of Project Settings.


#include "LITCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Lost_In_Time/Inventory/PickupItem.h"

ALITCharacter::ALITCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(GetMesh(), FName("Head"));
	FollowCamera->bUsePawnControlRotation = true;

	GetMesh()->HideBoneByName(FName("Head"), EPhysBodyOp::PBO_None);
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
	if (CollectedItem)
	{
		CollectedItem->ShowPickupWidget(false);

		if (CollectedItem->GetPickupCue())
		{
			UGameplayStatics::PlaySoundAtLocation(this, CollectedItem->GetPickupCue(), GetActorLocation());
		}

		CollectedItem->Interact();
	}
}

void ALITCharacter::SetCollectedItem(APickupItem* Item)
{
	if (CollectedItem)
	{
		CollectedItem->ShowPickupWidget(false);
	}

	CollectedItem = Item;

	if (CollectedItem)
	{
		CollectedItem->ShowPickupWidget(true);
	}
}
