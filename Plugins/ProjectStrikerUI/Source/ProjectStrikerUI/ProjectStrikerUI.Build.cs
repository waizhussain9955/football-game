using UnrealBuildTool;

public class ProjectStrikerUI : ModuleRules
{
	public ProjectStrikerUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "ProjectStrikerCore" });
	}
}
