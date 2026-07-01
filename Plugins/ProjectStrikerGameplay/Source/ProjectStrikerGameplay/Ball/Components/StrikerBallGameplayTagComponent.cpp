#include "Ball/Components/StrikerBallGameplayTagComponent.h"

UStrikerBallGameplayTagComponent::UStrikerBallGameplayTagComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallGameplayTagComponent::BeginPlay()
{
    Super::BeginPlay();
}
