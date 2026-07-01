#include "Ball/Components/StrikerBallStateComponent.h"

UStrikerBallStateComponent::UStrikerBallStateComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallStateComponent::BeginPlay()
{
    Super::BeginPlay();
}
