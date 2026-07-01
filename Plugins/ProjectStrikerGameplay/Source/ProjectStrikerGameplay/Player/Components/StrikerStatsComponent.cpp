#include "Player/Components/StrikerStatsComponent.h"

UStrikerStatsComponent::UStrikerStatsComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerStatsComponent::BeginPlay()
{
    Super::BeginPlay();
}
