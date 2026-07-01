#include "Ball/Components/StrikerBallSpinComponent.h"

UStrikerBallSpinComponent::UStrikerBallSpinComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallSpinComponent::BeginPlay()
{
    Super::BeginPlay();
}
