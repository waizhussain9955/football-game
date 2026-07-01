$Plugins = @(
    "ProjectStrikerAI",
    "ProjectStrikerPhysics",
    "ProjectStrikerAnimation",
    "ProjectStrikerTools",
    "ProjectStrikerEditor"
)

foreach ($Plugin in $Plugins) {
    $PluginDir = "d:\football-game\Plugins\$Plugin"
    $SourceDir = "$PluginDir\Source\$Plugin"
    New-Item -ItemType Directory -Force -Path $SourceDir | Out-Null

    $upluginContent = @"
{
	"FileVersion": 3,
	"Version": 1,
	"VersionName": "1.0",
	"FriendlyName": "$Plugin",
	"Description": "$Plugin module.",
	"Category": "Gameplay",
	"CreatedBy": "Waiz",
	"CanContainContent": true,
	"IsBetaVersion": false,
	"IsExperimentalVersion": false,
	"Installed": false,
	"Modules": [
		{
			"Name": "$Plugin",
			"Type": "Runtime",
			"LoadingPhase": "Default"
		}
	],
	"Plugins": [
		{
			"Name": "ProjectStrikerCore",
			"Enabled": true
		}
	]
}
"@
    Set-Content -Path "$PluginDir\$Plugin.uplugin" -Value $upluginContent

    $buildCsContent = @"
using UnrealBuildTool;

public class $Plugin : ModuleRules
{
	public $Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ProjectStrikerCore"
			}
		);
	}
}
"@
    Set-Content -Path "$SourceDir\$Plugin.Build.cs" -Value $buildCsContent
}

# Ensure Source dirs for Core and Gameplay exist too (since we only created the files earlier, wait we created the files in those dirs so they exist)
$CoreSourceDir = "d:\football-game\Plugins\ProjectStrikerCore\Source\ProjectStrikerCore"
$GameplaySourceDir = "d:\football-game\Plugins\ProjectStrikerGameplay\Source\ProjectStrikerGameplay"

New-Item -ItemType Directory -Force -Path $CoreSourceDir | Out-Null
New-Item -ItemType Directory -Force -Path $GameplaySourceDir | Out-Null

# Move Files
$SourceRoot = "d:\football-game\Source\ProjectStriker"

# 1. Core
Move-Item -Path "$SourceRoot\Player\StrikerTacticalRoles.h" -Destination $CoreSourceDir -ErrorAction SilentlyContinue

# 2. Gameplay (Managers, Entities, Camera, Environment)
Move-Item -Path "$SourceRoot\Managers" -Destination $GameplaySourceDir -ErrorAction SilentlyContinue
Move-Item -Path "$SourceRoot\Entities" -Destination $GameplaySourceDir -ErrorAction SilentlyContinue
Move-Item -Path "$SourceRoot\Camera" -Destination $GameplaySourceDir -ErrorAction SilentlyContinue
Move-Item -Path "$SourceRoot\Environment" -Destination $GameplaySourceDir -ErrorAction SilentlyContinue

# Create Player components dirs in Gameplay
$GameplayPlayerDir = "$GameplaySourceDir\Player\Components"
New-Item -ItemType Directory -Force -Path $GameplayPlayerDir | Out-Null

# Move specific components to Gameplay
$GameplayComponents = @("StrikerInputComponent.*", "StrikerBallControlComponent.*", "StrikerActionComponent.*", "StrikerPassingComponent.*", "StrikerShootingComponent.*", "StrikerCrossingComponent.*", "StrikerHeadingComponent.*", "StrikerTackleComponent.*", "StrikerInteractionComponent.*", "StrikerStaminaComponent.*", "StrikerStatsComponent.*")
foreach ($Comp in $GameplayComponents) {
    Move-Item -Path "$SourceRoot\Player\Components\$Comp" -Destination $GameplayPlayerDir -ErrorAction SilentlyContinue
}

# 3. AI
$AISourceDir = "d:\football-game\Plugins\ProjectStrikerAI\Source\ProjectStrikerAI"
New-Item -ItemType Directory -Force -Path "$AISourceDir\Player" | Out-Null
Move-Item -Path "$SourceRoot\Player\StrikerAIController.*" -Destination "$AISourceDir\Player\" -ErrorAction SilentlyContinue

# 4. Physics
$PhysicsSourceDir = "d:\football-game\Plugins\ProjectStrikerPhysics\Source\ProjectStrikerPhysics"
New-Item -ItemType Directory -Force -Path "$PhysicsSourceDir\Player\Components" | Out-Null
Move-Item -Path "$SourceRoot\Player\Components\StrikerCollisionComponent.*" -Destination "$PhysicsSourceDir\Player\Components\" -ErrorAction SilentlyContinue

# 5. Animation
$AnimSourceDir = "d:\football-game\Plugins\ProjectStrikerAnimation\Source\ProjectStrikerAnimation"
New-Item -ItemType Directory -Force -Path "$AnimSourceDir\Player\Components" | Out-Null
Move-Item -Path "$SourceRoot\Player\Components\StrikerLocomotionComponent.*" -Destination "$AnimSourceDir\Player\Components\" -ErrorAction SilentlyContinue
Move-Item -Path "$SourceRoot\Player\Components\StrikerAnimationComponent.*" -Destination "$AnimSourceDir\Player\Components\" -ErrorAction SilentlyContinue

Write-Output "Migration complete."
