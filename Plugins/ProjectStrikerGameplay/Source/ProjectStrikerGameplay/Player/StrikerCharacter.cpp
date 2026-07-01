#include "Player/StrikerCharacter.h"
#include "Player/Components/StrikerInputComponent.h"
#include "Player/Components/StrikerMovementStateComponent.h"
#include "Player/Components/StrikerLocomotionComponent.h"
#include "Player/Components/StrikerRotationComponent.h"
#include "Player/Components/StrikerCollisionComponent.h"
#include "Player/Components/StrikerInteractionComponent.h"
#include "Player/Components/StrikerStatsComponent.h"
#include "Player/Components/StrikerGameplayTagComponent.h"
#include "Player/Components/StrikerStaminaComponent.h"
#include "Player/Components/StrikerFootPlacementComponent.h"
#include "Player/Components/StrikerMovementPredictionComponent.h"
#include "Player/Components/StrikerDebugComponent.h"
#include "Player/Components/StrikerActionComponent.h"
// UStrikerAnimationComponent implementation exists in ProjectStrikerAnimation module
#include "Components/StrikerAnimationComponent.h"
#include "StrikerLog.h"

AStrikerCharacter::AStrikerCharacter()
{
    PrimaryActorTick.bCanEverTick = true; // Character needs tick, components don't

    // Instantiate exact Dependency Graph
    StrikerInput = CreateDefaultSubobject<UStrikerInputComponent>(TEXT("StrikerInput"));
    MovementState = CreateDefaultSubobject<UStrikerMovementStateComponent>(TEXT("MovementState"));
    Locomotion = CreateDefaultSubobject<UStrikerLocomotionComponent>(TEXT("Locomotion"));
    Rotation = CreateDefaultSubobject<UStrikerRotationComponent>(TEXT("Rotation"));
    StrikerCollision = CreateDefaultSubobject<UStrikerCollisionComponent>(TEXT("StrikerCollision"));
    Interaction = CreateDefaultSubobject<UStrikerInteractionComponent>(TEXT("Interaction"));
    Stats = CreateDefaultSubobject<UStrikerStatsComponent>(TEXT("Stats"));
    GameplayTag = CreateDefaultSubobject<UStrikerGameplayTagComponent>(TEXT("GameplayTag"));
    Stamina = CreateDefaultSubobject<UStrikerStaminaComponent>(TEXT("Stamina"));
    FootPlacement = CreateDefaultSubobject<UStrikerFootPlacementComponent>(TEXT("FootPlacement"));
    MovementPrediction = CreateDefaultSubobject<UStrikerMovementPredictionComponent>(TEXT("MovementPrediction"));
    Debug = CreateDefaultSubobject<UStrikerDebugComponent>(TEXT("Debug"));
    
    // Action Component Injection
    Action = CreateDefaultSubobject<UStrikerActionComponent>(TEXT("Action"));
    
    // Animation Component Injection
    Animation = CreateDefaultSubobject<UStrikerAnimationComponent>(TEXT("Animation"));
}

void AStrikerCharacter::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    // Strict Initialization Order Enforced
    // 1. Stats
    // 2. Gameplay Tags
    // 3. Locomotion / Movement
    // 4. Rotation
    // 5. Collision
    // 6. Interaction
    // 7. Action
    // 8. Debug
    // 9. Animation
}
