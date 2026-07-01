#include "Controllers/StrikerAIController.h"

AStrikerAIController::AStrikerAIController()
{
    PrimaryActorTick.bCanEverTick = false; // State Tree/Events drive behavior
}

void AStrikerAIController::BeginPlay()
{
    Super::BeginPlay();
}
