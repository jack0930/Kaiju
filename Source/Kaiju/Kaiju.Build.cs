// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Kaiju : ModuleRules
{
	public Kaiju(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "Niagara" });

		PublicIncludePaths.AddRange(new string[] {
			"Kaiju",
			"Kaiju/Variant_Strategy",
			"Kaiju/Variant_Strategy/UI",
			"Kaiju/Variant_TwinStick",
			"Kaiju/Variant_TwinStick/AI",
			"Kaiju/Variant_TwinStick/Gameplay",
			"Kaiju/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
