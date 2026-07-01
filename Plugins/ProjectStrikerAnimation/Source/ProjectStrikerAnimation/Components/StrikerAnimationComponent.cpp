#include "Components/StrikerAnimationComponent.h"

UStrikerAnimationComponent::UStrikerAnimationComponent()
{
    PrimaryComponentTick.bCanEverTick = true; // Animation component evaluates pose updates
}

void UStrikerAnimationComponent::BeginPlay()
{
    Super::BeginPlay();
}
