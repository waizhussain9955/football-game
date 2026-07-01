#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerStatsComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerStatsComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float SprintSpeedRating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float FinishingRating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float ShortPassRating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float StaminaRating;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void InitializeFromDataAsset(class UPrimaryDataAsset* DataAsset);
};
