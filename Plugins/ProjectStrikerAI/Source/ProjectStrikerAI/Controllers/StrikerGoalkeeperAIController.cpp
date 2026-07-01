#include "Controllers/StrikerGoalkeeperAIController.h"

AStrikerGoalkeeperAIController::AStrikerGoalkeeperAIController()
{
    PrimaryActorTick.bCanEverTick = false; // State Tree/Events drive behavior
}

void AStrikerGoalkeeperAIController::BeginPlay()
{
    Super::BeginPlay();
}
