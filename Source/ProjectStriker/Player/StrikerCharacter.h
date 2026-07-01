#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StrikerCharacter.generated.h"

class UStrikerLocomotionComponent;
class UStrikerBallControlComponent;
class UStrikerActionComponent;
class UStrikerTackleComponent;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Team")
	int32 TeamIndex;
};
