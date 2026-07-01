#include "Player/Components/StrikerStaminaComponent.h"

UStrikerStaminaComponent::UStrikerStaminaComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerStaminaComponent::BeginPlay()
{
    Super::BeginPlay();
}
