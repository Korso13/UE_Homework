// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Test3P_Proj : ModuleRules
{
	public Test3P_Proj(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
