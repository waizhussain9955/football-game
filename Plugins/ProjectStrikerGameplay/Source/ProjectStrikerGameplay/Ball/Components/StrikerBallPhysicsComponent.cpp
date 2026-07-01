#include "Ball/Components/StrikerBallPhysicsComponent.h"

UStrikerBallPhysicsComponent::UStrikerBallPhysicsComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}

void UStrikerBallPhysicsComponent::BeginPlay()
{
    Super::BeginPlay();
}
