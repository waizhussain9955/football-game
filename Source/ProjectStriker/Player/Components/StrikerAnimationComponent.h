#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerAnimationComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKER_API UStrikerAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerAnimationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void PlayDynamicMontage(UAnimMontage* MontageToPlay, float PlayRate);
};
