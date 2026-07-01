#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerFootPlacementComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerFootPlacementComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerFootPlacementComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
