#include "Player/Components/StrikerInteractionComponent.h"

UStrikerInteractionComponent::UStrikerInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerInteractionComponent::BeginPlay()
{
    Super::BeginPlay();
}
