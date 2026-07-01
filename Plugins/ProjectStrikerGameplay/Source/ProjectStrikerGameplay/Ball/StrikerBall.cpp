#include "Ball/StrikerBall.h"
#include "Ball/Components/StrikerBallPhysicsComponent.h"
#include "Ball/Components/StrikerBallCollisionComponent.h"
#include "Ball/Components/StrikerBallOwnershipComponent.h"
#include "Ball/Components/StrikerBallTrajectoryComponent.h"
#include "Ball/Components/StrikerBallSpinComponent.h"
#include "Ball/Components/StrikerBallStateComponent.h"
#include "Ball/Components/StrikerBallControlComponent.h"
#include "Ball/Components/StrikerBallReplicationComponent.h"
#include "Ball/Components/StrikerBallGameplayTagComponent.h"
#include "Ball/Components/StrikerBallDebugComponent.h"
#include "StrikerLog.h"

AStrikerBall::AStrikerBall()
{
    PrimaryActorTick.bCanEverTick = true; // Actor ticks, components do not unless physics-driven

    // Instantiate exact Dependency Graph
    BallPhysics = CreateDefaultSubobject<UStrikerBallPhysicsComponent>(TEXT("BallPhysics"));
    BallCollision = CreateDefaultSubobject<UStrikerBallCollisionComponent>(TEXT("BallCollision"));
    GameplayTag = CreateDefaultSubobject<UStrikerBallGameplayTagComponent>(TEXT("GameplayTag"));
    Ownership = CreateDefaultSubobject<UStrikerBallOwnershipComponent>(TEXT("Ownership"));
    Trajectory = CreateDefaultSubobject<UStrikerBallTrajectoryComponent>(TEXT("Trajectory"));
    State = CreateDefaultSubobject<UStrikerBallStateComponent>(TEXT("State"));
    Spin = CreateDefaultSubobject<UStrikerBallSpinComponent>(TEXT("Spin"));
    Control = CreateDefaultSubobject<UStrikerBallControlComponent>(TEXT("Control"));
    Replication = CreateDefaultSubobject<UStrikerBallReplicationComponent>(TEXT("Replication"));
    Debug = CreateDefaultSubobject<UStrikerBallDebugComponent>(TEXT("Debug"));
}

void AStrikerBall::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    // Strict Initialization Order Enforced
    // 1. Physics
    // 2. Collision
    // 3. Gameplay Tags
    // 4. Ownership
    // 5. Trajectory
    // 6. State Machine
    // 7. Replication
    // 8. Debug
}
