using UnrealBuildTool;

public class ProjectStrikerDeveloper : ModuleRules
{
	public ProjectStrikerDeveloper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "ProjectStrikerCore" });
	}
}
