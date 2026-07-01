#include "Controllers/StrikerRefereeAIController.h"

AStrikerRefereeAIController::AStrikerRefereeAIController()
{
    PrimaryActorTick.bCanEverTick = false; // State Tree/Events drive behavior
}

void AStrikerRefereeAIController::BeginPlay()
{
    Super::BeginPlay();
}
