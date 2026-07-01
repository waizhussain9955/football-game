#include "Ball/Components/StrikerBallControlComponent.h"

UStrikerBallControlComponent::UStrikerBallControlComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallControlComponent::BeginPlay()
{
    Super::BeginPlay();
}
