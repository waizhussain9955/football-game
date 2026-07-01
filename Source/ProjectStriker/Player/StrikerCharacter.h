#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StrikerCharacter.generated.h"

class UStrikerLocomotionComponent;
class UStrikerBallControlComponent;
class UStrikerActionComponent;
class UStrikerTackleComponent;
class UStrikerAnimationComponent;
class UStrikerInputComponent;
class UStrikerPassingComponent;
class UStrikerShootingComponent;
class UStrikerCrossingComponent;
class UStrikerHeadingComponent;
class UStrikerCollisionComponent;
class UStrikerInteractionComponent;
class UStrikerStaminaComponent;
class UStrikerStatsComponent;

UCLASS()
class PROJECTSTRIKER_API AStrikerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStrikerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerLocomotionComponent* LocomotionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerBallControlComponent* BallControlComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerActionComponent* ActionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerTackleComponent* TackleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerAnimationComponent* AnimationComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerInputComponent* StrikerInputComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerPassingComponent* PassingComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerShootingComponent* ShootingComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerCrossingComponent* CrossingComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerHeadingComponent* HeadingComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerCollisionComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerStaminaComponent* StaminaComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStrikerStatsComponent* StatsComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Team")
	int32 TeamIndex;
};
