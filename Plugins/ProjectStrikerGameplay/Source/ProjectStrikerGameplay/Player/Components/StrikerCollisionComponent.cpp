#include "Player/Components/StrikerCollisionComponent.h"

UStrikerCollisionComponent::UStrikerCollisionComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerCollisionComponent::BeginPlay()
{
    Super::BeginPlay();
}
