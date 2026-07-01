import os

base_dir = r"d:\football-game\Plugins\ProjectStrikerGameplay\Source\ProjectStrikerGameplay"
ball_dir = os.path.join(base_dir, "Ball")
comp_dir = os.path.join(ball_dir, "Components")
data_dir = os.path.join(base_dir, "DataAssets", "Ball")
events_dir = os.path.join(base_dir, "Events")

os.makedirs(comp_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)
os.makedirs(events_dir, exist_ok=True)

# 1. Append Enums to StrikerGameplayEvents.h
events_path = os.path.join(events_dir, "StrikerGameplayEvents.h")
if os.path.exists(events_path):
    with open(events_path, "a") as f:
        f.write(r"""
UENUM(BlueprintType)
enum class EStrikerBallState : uint8
{
    Idle, Ready, Kickoff, Controlled, Loose, Rolling, Sliding, Airborne, Curving, Bouncing, Deflected, Intercepted, OutOfPlay, Goal, Replay, Frozen, Destroyed
};
""")

# 2. Generate Components
components = [
    "StrikerBallPhysicsComponent",
    "StrikerBallCollisionComponent",
    "StrikerBallOwnershipComponent",
    "StrikerBallTrajectoryComponent",
    "StrikerBallSpinComponent",
    "StrikerBallStateComponent",
    "StrikerBallControlComponent",
    "StrikerBallReplicationComponent",
    "StrikerBallGameplayTagComponent",
    "StrikerBallDebugComponent"
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
}};
"""
    # CPP
    cpp_content = f"""#include "Ball/Components/{comp}.h"

U{comp}::U{comp}()
{{
    PrimaryComponentTick.bCanEverTick = false; // Physics evaluated externally or natively
}}

void U{comp}::BeginPlay()
{{
    Super::BeginPlay();
}}
"""
    with open(os.path.join(comp_dir, f"{comp}.h"), "w") as f: f.write(h_content)
    with open(os.path.join(comp_dir, f"{comp}.cpp"), "w") as f: f.write(cpp_content)

# 3. Generate Data Assets
data_assets = [
    "BallPhysicsProfile",
    "BallMaterialProfile",
    "BallGameplayProfile",
    "BallVisualProfile",
    "BallAudioProfile"
]

for da in data_assets:
    da_h = f"""#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "{da}.generated.h"

UCLASS(BlueprintType)
class PROJECTSTRIKERGAMEPLAY_API U{da} : public UDataAsset
{{
    GENERATED_BODY()
public:
    // Configurable properties to be defined in Blueprints
}};
"""
    da_cpp = f"""#include "DataAssets/Ball/{da}.h"
"""
    with open(os.path.join(data_dir, f"{da}.h"), "w") as f: f.write(da_h)
    with open(os.path.join(data_dir, f"{da}.cpp"), "w") as f: f.write(da_cpp)

# 4. Generate AStrikerBall Shell
char_h = r"""#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrikerBall.generated.h"

// Forward Declarations
class UStrikerBallPhysicsComponent;
class UStrikerBallCollisionComponent;
class UStrikerBallOwnershipComponent;
class UStrikerBallTrajectoryComponent;
class UStrikerBallSpinComponent;
class UStrikerBallStateComponent;
class UStrikerBallControlComponent;
class UStrikerBallReplicationComponent;
class UStrikerBallGameplayTagComponent;
class UStrikerBallDebugComponent;

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API AStrikerBall : public AActor
{
    GENERATED_BODY()
public:
    AStrikerBall();

    // Mandatory Dependency Graph Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallPhysicsComponent* BallPhysics;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallCollisionComponent* BallCollision;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallOwnershipComponent* Ownership;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallTrajectoryComponent* Trajectory;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallSpinComponent* Spin;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallStateComponent* State;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallControlComponent* Control;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallReplicationComponent* Replication;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallGameplayTagComponent* GameplayTag;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerBallDebugComponent* Debug;

protected:
    virtual void PostInitializeComponents() override;
};
"""

char_cpp = r"""#include "Ball/StrikerBall.h"
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
"""
with open(os.path.join(ball_dir, "StrikerBall.h"), "w") as f: f.write(char_h)
with open(os.path.join(ball_dir, "StrikerBall.cpp"), "w") as f: f.write(char_cpp)

print("Part 6 Ball generation complete.")
