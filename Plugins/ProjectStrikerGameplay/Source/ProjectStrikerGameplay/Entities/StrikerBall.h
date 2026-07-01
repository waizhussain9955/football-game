#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrikerBall.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class AStrikerCharacter;

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API AStrikerBall : public AActor
{
	GENERATED_BODY()
	
public:	
	AStrikerBall();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// Advanced Physics Data
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Physics")
	FVector CurrentSpin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float MagnusCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float GroundFrictionCoefficient;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ownership")
	AStrikerCharacter* LastTouchedBy;

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void ApplyKickImpulse(FVector Direction, float Force, FVector SpinAmount);

private:
	void CalculateMagnusEffect(float DeltaTime);
	void DetectGoalAndPossession();
};
