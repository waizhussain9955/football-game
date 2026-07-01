import os

base_dir = r"d:\football-game\Plugins\ProjectStrikerGameplay\Source\ProjectStrikerGameplay"
player_dir = os.path.join(base_dir, "Player")
comp_dir = os.path.join(player_dir, "Components")
events_dir = os.path.join(base_dir, "Events")

os.makedirs(comp_dir, exist_ok=True)
os.makedirs(events_dir, exist_ok=True)

# 1. Append Enums to StrikerGameplayEvents.h
events_path = os.path.join(events_dir, "StrikerGameplayEvents.h")
if os.path.exists(events_path):
    with open(events_path, "a") as f:
        f.write(r"""
UENUM(BlueprintType)
enum class EStrikerMovementState : uint8
{
    Idle, Walk, Jog, Run, Sprint, Accelerating, Decelerating,
    TurnLeft, TurnRight, Pivot, Stop, Backpedal, StrafeLeft, StrafeRight,
    Jump, Land, Recover, Stunned, Fallen, GettingUp, Disabled
};

UENUM(BlueprintType)
enum class EStrikerPlayerStatus : uint8
{
    Alive, Active, Recovering, Disabled
};
""")

# 2. Generate Components
components = [
    "StrikerInputComponent",
    "StrikerMovementStateComponent",
    "StrikerLocomotionComponent",
    "StrikerRotationComponent",
    "StrikerCollisionComponent",
    "StrikerInteractionComponent",
    "StrikerStatsComponent",
    "StrikerGameplayTagComponent",
    "StrikerStaminaComponent",
    "StrikerFootPlacementComponent",
    "StrikerMovementPredictionComponent",
    "StrikerDebugComponent"
]

for comp in components:
    # Header
    h_content = f"""#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "{comp}.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API U{comp} : public UActorComponent
{{
    GENERATED_BODY()
public:	
    U{comp}();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
}};
"""
    # CPP
    cpp_content = f"""#include "Player/Components/{comp}.h"

U{comp}::U{comp}()
{{
    PrimaryComponentTick.bCanEverTick = false; // Strictly enforced
}}

void U{comp}::BeginPlay()
{{
    Super::BeginPlay();
}}
"""
    with open(os.path.join(comp_dir, f"{comp}.h"), "w") as f: f.write(h_content)
    with open(os.path.join(comp_dir, f"{comp}.cpp"), "w") as f: f.write(cpp_content)

# 3. Generate AStrikerCharacter Shell
char_h = r"""#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StrikerCharacter.generated.h"

// Forward Declarations
class UStrikerInputComponent;
class UStrikerMovementStateComponent;
class UStrikerLocomotionComponent;
class UStrikerRotationComponent;
class UStrikerCollisionComponent;
class UStrikerInteractionComponent;
class UStrikerStatsComponent;
class UStrikerGameplayTagComponent;
class UStrikerStaminaComponent;
class UStrikerFootPlacementComponent;
class UStrikerMovementPredictionComponent;
class UStrikerDebugComponent;

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API AStrikerCharacter : public ACharacter
{
    GENERATED_BODY()
public:
    AStrikerCharacter();

    // Mandatory Dependency Graph Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerInputComponent* StrikerInput;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerMovementStateComponent* MovementState;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerLocomotionComponent* Locomotion;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerRotationComponent* Rotation;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerCollisionComponent* StrikerCollision;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerInteractionComponent* Interaction;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerStatsComponent* Stats;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerGameplayTagComponent* GameplayTag;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerStaminaComponent* Stamina;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerFootPlacementComponent* FootPlacement;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerMovementPredictionComponent* MovementPrediction;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerDebugComponent* Debug;

protected:
    virtual void PostInitializeComponents() override;
};
"""

char_cpp = r"""#include "Player/StrikerCharacter.h"
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
    // 7. Animation (Future)
    // 8. Debug
}
"""
with open(os.path.join(player_dir, "StrikerCharacter.h"), "w") as f: f.write(char_h)
with open(os.path.join(player_dir, "StrikerCharacter.cpp"), "w") as f: f.write(char_cpp)

print("Part 5 Player generation complete.")
