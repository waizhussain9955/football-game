#include "Player/Components/StrikerGameplayTagComponent.h"

UStrikerGameplayTagComponent::UStrikerGameplayTagComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerGameplayTagComponent::BeginPlay()
{
    Super::BeginPlay();
}
