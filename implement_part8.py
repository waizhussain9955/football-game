import os

base_dir = r"d:\football-game\Plugins\ProjectStrikerAI\Source\ProjectStrikerAI"
ctrl_dir = os.path.join(base_dir, "Controllers")
data_dir = os.path.join(base_dir, "DataAssets")

os.makedirs(ctrl_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)

# 1. Generate Controllers
controllers = [
    ("StrikerAIController", "AAIController", "AIController.h"),
    ("StrikerGoalkeeperAIController", "AStrikerAIController", "Controllers/StrikerAIController.h"),
    ("StrikerRefereeAIController", "AStrikerAIController", "Controllers/StrikerAIController.h")
]

for cls, parent, include in controllers:
    h_content = f"""#pragma once
#include "CoreMinimal.h"
#include "{include}"
#include "{cls}.generated.h"

UCLASS()
class PROJECTSTRIKERAI_API A{cls} : public {parent}
{{
    GENERATED_BODY()
public:
    A{cls}();
protected:
    virtual void BeginPlay() override;
}};
"""
    cpp_content = f"""#include "Controllers/{cls}.h"

A{cls}::A{cls}()
{{
    PrimaryActorTick.bCanEverTick = false; // State Tree/Events drive behavior
}}

void A{cls}::BeginPlay()
{{
    Super::BeginPlay();
}}
"""
    with open(os.path.join(ctrl_dir, f"{cls}.h"), "w") as f: f.write(h_content)
    with open(os.path.join(ctrl_dir, f"{cls}.cpp"), "w") as f: f.write(cpp_content)

# 2. Generate Data Assets
data_assets = [
    "AIProfile",
    "TacticalProfile",
    "FormationProfile",
    "GoalkeeperProfile",
    "RefereeProfile",
    "TeamProfile"
]

for da in data_assets:
    da_h = f"""#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "{da}.generated.h"

UCLASS(BlueprintType)
class PROJECTSTRIKERAI_API U{da} : public UDataAsset
{{
    GENERATED_BODY()
public:
    // Configurable properties to be defined in Blueprints
}};
"""
    da_cpp = f"""#include "DataAssets/{da}.h"
"""
    with open(os.path.join(data_dir, f"{da}.h"), "w") as f: f.write(da_h)
    with open(os.path.join(data_dir, f"{da}.cpp"), "w") as f: f.write(da_cpp)

print("Part 8 AI generation complete.")
