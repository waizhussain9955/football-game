#include "Player/Components/StrikerLocomotionComponent.h"

UStrikerLocomotionComponent::UStrikerLocomotionComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerLocomotionComponent::BeginPlay()
{
    Super::BeginPlay();
}
