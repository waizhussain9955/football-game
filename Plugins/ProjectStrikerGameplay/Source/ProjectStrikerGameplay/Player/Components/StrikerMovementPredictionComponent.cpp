#include "Player/Components/StrikerMovementPredictionComponent.h"

UStrikerMovementPredictionComponent::UStrikerMovementPredictionComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}

void UStrikerMovementPredictionComponent::BeginPlay()
{
    Super::BeginPlay();
}
