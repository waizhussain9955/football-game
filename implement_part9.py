import os

anim_base = r"d:\football-game\Plugins\ProjectStrikerAnimation\Source\ProjectStrikerAnimation"
gameplay_base = r"d:\football-game\Plugins\ProjectStrikerGameplay\Source\ProjectStrikerGameplay"

comp_dir = os.path.join(anim_base, "Components")
data_dir = os.path.join(anim_base, "DataAssets")
events_dir = os.path.join(gameplay_base, "Events")
player_dir = os.path.join(gameplay_base, "Player")

os.makedirs(comp_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)
os.makedirs(events_dir, exist_ok=True)

# 1. Append Enums to StrikerGameplayEvents.h
events_path = os.path.join(events_dir, "StrikerGameplayEvents.h")
if os.path.exists(events_path):
    with open(events_path, "a") as f:
        f.write(r"""
UENUM(BlueprintType)
enum class EStrikerAnimationState : uint8
{
    Locomotion, FootballActions, Goalkeeper, Referee, Celebration, SetPieces, Injury, Recovery, Disabled
};
""")

# 2. Generate Animation Component
h_content = f"""#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerAnimationComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERANIMATION_API UStrikerAnimationComponent : public UActorComponent
{{
    GENERATED_BODY()
public:	
    UStrikerAnimationComponent();
protected:
    virtual void BeginPlay() override;
}};
"""
cpp_content = f"""#include "Components/StrikerAnimationComponent.h"

UStrikerAnimationComponent::UStrikerAnimationComponent()
{{
    PrimaryComponentTick.bCanEverTick = true; // Animation component evaluates pose updates
}}

void UStrikerAnimationComponent::BeginPlay()
{{
    Super::BeginPlay();
}}
"""
with open(os.path.join(comp_dir, "StrikerAnimationComponent.h"), "w") as f: f.write(h_content)
with open(os.path.join(comp_dir, "StrikerAnimationComponent.cpp"), "w") as f: f.write(cpp_content)


# 3. Generate Data Assets
data_assets = [
    "AnimationProfile",
    "MotionMatchingProfile",
    "PoseSearchProfile",
    "RootMotionProfile",
    "IKProfile",
    "AnimationLayerProfile"
]

for da in data_assets:
    da_h = f"""#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "{da}.generated.h"

UCLASS(BlueprintType)
class PROJECTSTRIKERANIMATION_API U{da} : public UDataAsset
{{
    GENERATED_BODY()
public:
    // Configurable properties to be defined in Blueprints
}};
"""
    da_cpp = f"""#include "DataAssets/{da}.h"
"""
    with open(os.path.join(data_dir, f"{da}.h"), "w") as f: f.write(da_h)
    with open(os.path.join(data_dir, f"{da}.cpp"), "w") as f: f.write(da_cpp)

# 4. Modify AStrikerCharacter Shell
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
class UStrikerActionComponent;
class UStrikerAnimationComponent;

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

    // Action Component Injection (Part 7)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerActionComponent* Action;
    
    // Animation Component Injection (Part 9)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Striker|Components")
    UStrikerAnimationComponent* Animation;

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
"""
with open(os.path.join(player_dir, "StrikerCharacter.h"), "w") as f: f.write(char_h)
with open(os.path.join(player_dir, "StrikerCharacter.cpp"), "w") as f: f.write(char_cpp)

print("Part 9 Animation generation complete.")
