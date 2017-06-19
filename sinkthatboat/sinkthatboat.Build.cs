// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class sinkthatboat : ModuleRules
{
	public sinkthatboat(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });


        //SQL lib added by SinkThatBoat Team (Surtout Clément qui fait tout sur ce projet)
        PublicAdditionalLibraries.Add(@"C:/PortesOuvertes/sinkthatboat/Binaries/Win64/libmysql.lib");

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

    }
}
