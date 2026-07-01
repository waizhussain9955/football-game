#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerActionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerActionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void PassBall(FVector TargetDirection, float Power);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void ShootBall(FVector TargetDirection, float Power);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void CrossBall(FVector TargetDirection, float Power);
};
