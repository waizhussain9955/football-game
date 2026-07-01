#include "StrikerAIController.h"
#include "StrikerCharacter.h"

AStrikerAIController::AStrikerAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStrikerAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	// Start behavior tree logic
}

void AStrikerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Update AI tactical decisions
}
