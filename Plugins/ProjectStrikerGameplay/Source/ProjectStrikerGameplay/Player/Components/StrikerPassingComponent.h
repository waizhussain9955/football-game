#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerPassingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerPassingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerPassingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Passing")
	void ExecuteShortPass(float Power);

	UFUNCTION(BlueprintCallable, Category = "Passing")
	void ExecuteLongPass(float Power);

	UFUNCTION(BlueprintCallable, Category = "Passing")
	void ExecuteThroughPass(float Power);
};
