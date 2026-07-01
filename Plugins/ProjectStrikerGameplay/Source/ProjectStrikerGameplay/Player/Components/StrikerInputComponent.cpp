#include "Player/Components/StrikerInputComponent.h"

UStrikerInputComponent::UStrikerInputComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerInputComponent::BeginPlay()
{
    Super::BeginPlay();
}
