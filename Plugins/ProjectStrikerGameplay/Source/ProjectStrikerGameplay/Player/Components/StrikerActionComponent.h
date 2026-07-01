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
};
