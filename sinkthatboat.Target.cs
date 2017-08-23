// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class sinkthatboatTarget : TargetRules {
    public sinkthatboatTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Game;
        ExtraModuleNames.Add("sinkthatboat");
    }
}
