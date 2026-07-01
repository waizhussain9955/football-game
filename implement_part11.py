import os

core_base = r"d:\football-game\Plugins\ProjectStrikerCore\Source\ProjectStrikerCore"

env_dir = os.path.join(core_base, "Environment")
data_dir = os.path.join(core_base, "DataAssets", "Environment")

os.makedirs(env_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)

# 1. Generate Actors and Managers
managers = [
    ("StrikerStadium", "AActor", "GameFramework/Actor.h", env_dir),
    ("StrikerWeatherManager", "UGameInstanceSubsystem", "Subsystems/GameInstanceSubsystem.h", env_dir),
    ("StrikerLightingManager", "UGameInstanceSubsystem", "Subsystems/GameInstanceSubsystem.h", env_dir)
]

for cls, parent, include, dir_path in managers:
    h_content = f"""#pragma once
#include "CoreMinimal.h"
#include "{include}"
#include "{cls}.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API {"A" if parent.startswith("A") else "U"}{cls} : public {parent}
{{
    GENERATED_BODY()
public:
    {"A" if parent.startswith("A") else "U"}{cls}();
}};
"""
    cpp_content = f"""#include "Environment/{cls}.h"

{"A" if parent.startswith("A") else "U"}{cls}::{"A" if parent.startswith("A") else "U"}{cls}()
{{
}}
"""
    with open(os.path.join(dir_path, f"{cls}.h"), "w") as f: f.write(h_content)
    with open(os.path.join(dir_path, f"{cls}.cpp"), "w") as f: f.write(cpp_content)


# 2. Generate Data Assets
data_assets = [
    "StadiumProfile",
    "PitchProfile",
    "GrassProfile",
    "WeatherProfile",
    "LightingProfile",
    "RenderProfile",
    "GraphicsProfile",
    "VFXProfile"
]

for da in data_assets:
    da_h = f"""#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "{da}.generated.h"

UCLASS(BlueprintType)
class PROJECTSTRIKERCORE_API U{da} : public UDataAsset
{{
    GENERATED_BODY()
public:
    // Configurable environment and graphics properties to be defined in Blueprints
}};
"""
    da_cpp = f"""#include "DataAssets/Environment/{da}.h"
"""
    with open(os.path.join(data_dir, f"{da}.h"), "w") as f: f.write(da_h)
    with open(os.path.join(data_dir, f"{da}.cpp"), "w") as f: f.write(da_cpp)

print("Part 11 Environment generation complete.")
