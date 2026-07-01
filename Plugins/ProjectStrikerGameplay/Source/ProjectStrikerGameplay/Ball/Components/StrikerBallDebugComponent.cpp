#include "Ball/Components/StrikerBallDebugComponent.h"

UStrikerBallDebugComponent::UStrikerBallDebugComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallDebugComponent::BeginPlay()
{
    Super::BeginPlay();
}
