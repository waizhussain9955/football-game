#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerGameplayTagComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerGameplayTagComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerGameplayTagComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
