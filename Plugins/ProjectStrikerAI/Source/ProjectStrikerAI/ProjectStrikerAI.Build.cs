using UnrealBuildTool;

public class ProjectStrikerAI : ModuleRules
{
	public ProjectStrikerAI(ReadOnlyTargetRules Target) : base(Target)
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
