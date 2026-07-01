using UnrealBuildTool;

public class ProjectStrikerAnimation : ModuleRules
{
	public ProjectStrikerAnimation(ReadOnlyTargetRules Target) : base(Target)
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
