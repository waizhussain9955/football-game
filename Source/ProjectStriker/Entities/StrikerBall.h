#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrikerBall.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class PROJECTSTRIKER_API AStrikerBall : public AActor
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

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void ApplyKickImpulse(FVector Direction, float Force);
};
