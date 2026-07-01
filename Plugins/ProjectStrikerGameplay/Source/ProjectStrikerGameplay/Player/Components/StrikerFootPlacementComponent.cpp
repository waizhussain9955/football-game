#include "Player/Components/StrikerFootPlacementComponent.h"

UStrikerFootPlacementComponent::UStrikerFootPlacementComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerFootPlacementComponent::BeginPlay()
{
    Super::BeginPlay();
}
