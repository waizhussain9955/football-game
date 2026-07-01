#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallControlComponent.generated.h"

class AStrikerBall;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerBallControlComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ball Control")
	AStrikerBall* ControlledBall;

	UFUNCTION(BlueprintCallable, Category = "Ball Control")
	bool HasPossession() const;

	UFUNCTION(BlueprintCallable, Category = "Ball Control")
	void ReceiveBall(AStrikerBall* Ball);

	UFUNCTION(BlueprintCallable, Category = "Ball Control")
	void ReleaseBall();
};
