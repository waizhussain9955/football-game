#include "Player/Components/StrikerMovementStateComponent.h"

UStrikerMovementStateComponent::UStrikerMovementStateComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerMovementStateComponent::BeginPlay()
{
    Super::BeginPlay();
}
