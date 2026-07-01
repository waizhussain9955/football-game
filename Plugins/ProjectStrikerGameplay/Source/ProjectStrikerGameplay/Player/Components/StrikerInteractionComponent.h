#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerInteractionComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerInteractionComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
