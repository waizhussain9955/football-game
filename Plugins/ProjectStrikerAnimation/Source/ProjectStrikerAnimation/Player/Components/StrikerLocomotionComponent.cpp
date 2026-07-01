#include "StrikerLocomotionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

UStrikerLocomotionComponent::UStrikerLocomotionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	BaseSpeed = 400.0f;
	SprintSpeed = 700.0f;
}

void UStrikerLocomotionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerLocomotionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerLocomotionComponent::SetSprinting(bool bIsSprinting)
{
	if (ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner()))
	{
		if (UCharacterMovementComponent* MovementComp = OwnerCharacter->GetCharacterMovement())
		{
			MovementComp->MaxWalkSpeed = bIsSprinting ? SprintSpeed : BaseSpeed;
		}
	}
}
