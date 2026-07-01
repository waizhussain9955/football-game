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
    // Interfaces / Delegate Hooks
};
