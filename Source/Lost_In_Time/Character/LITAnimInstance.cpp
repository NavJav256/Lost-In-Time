// Fill out your copyright notice in the Description page of Project Settings.


#include "LITAnimInstance.h"
#include "Lost_In_Time/Character/LITCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ULITAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	LITCharacter = Cast<ALITCharacter>(TryGetPawnOwner());
}

void ULITAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if(LITCharacter == nullptr) Cast<ALITCharacter>(TryGetPawnOwner());

	if (LITCharacter == nullptr) return;

	FVector Velocity = LITCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = LITCharacter->GetCharacterMovement()->IsFalling();
}
