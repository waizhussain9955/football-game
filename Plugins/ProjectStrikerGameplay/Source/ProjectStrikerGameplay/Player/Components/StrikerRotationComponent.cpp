#include "Player/Components/StrikerRotationComponent.h"

UStrikerRotationComponent::UStrikerRotationComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerRotationComponent::BeginPlay()
{
    Super::BeginPlay();
}
