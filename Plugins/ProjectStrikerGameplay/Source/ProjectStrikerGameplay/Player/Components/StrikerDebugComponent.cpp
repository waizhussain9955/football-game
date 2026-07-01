#include "Player/Components/StrikerDebugComponent.h"

UStrikerDebugComponent::UStrikerDebugComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerDebugComponent::BeginPlay()
{
    Super::BeginPlay();
}
