import os

core_base = r"d:\football-game\Plugins\ProjectStrikerCore\Source\ProjectStrikerCore"

net_dir = os.path.join(core_base, "Production", "Networking")
save_dir = os.path.join(core_base, "Production", "Save")
data_dir = os.path.join(core_base, "DataAssets", "Production")

os.makedirs(net_dir, exist_ok=True)
os.makedirs(save_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)

# 1. Generate Managers and Payloads
classes = [
    ("StrikerNetworkManager", "UGameInstanceSubsystem", "Subsystems/GameInstanceSubsystem.h", net_dir),
    ("StrikerSaveManager", "UGameInstanceSubsystem", "Subsystems/GameInstanceSubsystem.h", save_dir),
    ("StrikerSaveGame", "USaveGame", "GameFramework/SaveGame.h", save_dir)
]

for cls, parent, include, dir_path in classes:
    h_content = f"""#pragma once
#include "CoreMinimal.h"
#include "{include}"
#include "{cls}.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API U{cls} : public {parent}
{{
    GENERATED_BODY()
public:
    U{cls}();
}};
"""
    cpp_content = f"""#include "Production/{os.path.basename(dir_path)}/{cls}.h"

U{cls}::U{cls}()
{{
}}
"""
    with open(os.path.join(dir_path, f"{cls}.h"), "w") as f: f.write(h_content)
    with open(os.path.join(dir_path, f"{cls}.cpp"), "w") as f: f.write(cpp_content)


# 2. Generate Data Assets
data_assets = [
    "NetworkProfile",
    "SaveProfile",
    "CareerProfile",
    "TournamentProfile",
    "BuildProfile",
    "AnalyticsProfile",
    "LiveOpsProfile"
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
    // Configurable production parameters to be defined in Blueprints
}};
"""
    da_cpp = f"""#include "DataAssets/Production/{da}.h"
"""
    with open(os.path.join(data_dir, f"{da}.h"), "w") as f: f.write(da_h)
    with open(os.path.join(data_dir, f"{da}.cpp"), "w") as f: f.write(da_cpp)

print("Part 12 Production generation complete.")
