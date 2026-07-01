using UnrealBuildTool;

public class ProjectStrikerTesting : ModuleRules
{
	public ProjectStrikerTesting(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "ProjectStrikerCore" });
	}
}
