#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerCrossingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerCrossingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerCrossingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Crossing")
	void ExecuteCross(float Power, FVector TargetArea);

	UFUNCTION(BlueprintCallable, Category = "Crossing")
	void ExecuteEarlyCross(float Power, FVector TargetArea);
};
