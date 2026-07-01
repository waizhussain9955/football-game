#include "StrikerAIController.h"
#include "StrikerCharacter.h"

AStrikerAIController::AStrikerAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	AssignedRole = EStrikerTacticalRole::CentralMidfielder;
	ActiveStateTree = nullptr;
}

void AStrikerAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// Initialize State Tree logic via UStateTreeComponent if added
}

void AStrikerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Tactical evaluations happen here, State Tree handles execution
}

void AStrikerAIController::AssignRole(EStrikerTacticalRole NewRole, UStateTree* RoleStateTree)
{
	AssignedRole = NewRole;
	ActiveStateTree = RoleStateTree;
	// Restart State Tree with new role parameters
}
