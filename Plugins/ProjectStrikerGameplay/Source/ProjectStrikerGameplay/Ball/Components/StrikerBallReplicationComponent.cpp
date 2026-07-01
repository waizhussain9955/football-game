#include "Ball/Components/StrikerBallReplicationComponent.h"

UStrikerBallReplicationComponent::UStrikerBallReplicationComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallReplicationComponent::BeginPlay()
{
    Super::BeginPlay();
}
