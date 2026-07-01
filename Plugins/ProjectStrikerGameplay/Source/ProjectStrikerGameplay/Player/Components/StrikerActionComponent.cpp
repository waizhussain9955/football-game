#include "Player/Components/StrikerActionComponent.h"

UStrikerActionComponent::UStrikerActionComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Event driven only
}

void UStrikerActionComponent::BeginPlay()
{
    Super::BeginPlay();
}
