#include "Ball/Components/StrikerBallTrajectoryComponent.h"

UStrikerBallTrajectoryComponent::UStrikerBallTrajectoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallTrajectoryComponent::BeginPlay()
{
    Super::BeginPlay();
}
