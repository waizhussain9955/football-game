#include "Ball/Components/StrikerBallCollisionComponent.h"

UStrikerBallCollisionComponent::UStrikerBallCollisionComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallCollisionComponent::BeginPlay()
{
    Super::BeginPlay();
}
