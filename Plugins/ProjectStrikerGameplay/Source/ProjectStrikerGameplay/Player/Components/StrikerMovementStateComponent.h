#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerMovementStateComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerMovementStateComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerMovementStateComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
