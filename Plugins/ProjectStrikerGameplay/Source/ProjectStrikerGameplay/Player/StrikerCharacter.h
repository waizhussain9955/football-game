#pragma once
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
