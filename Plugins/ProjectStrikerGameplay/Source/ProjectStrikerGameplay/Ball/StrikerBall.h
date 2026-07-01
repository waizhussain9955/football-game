#pragma once
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
