#include "Ball/Components/StrikerBallOwnershipComponent.h"

UStrikerBallOwnershipComponent::UStrikerBallOwnershipComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallOwnershipComponent::BeginPlay()
{
    Super::BeginPlay();
}
