//
#pragma once

#include "../Header.h"
#include "EngineUtils.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LIB_Cpp.generated.h"

/**
 * 
 */
UCLASS()
class SINKTHATBOAT_API ULIB_Cpp : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getSealCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getChickenCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getElephantCooldown();
		
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getPandaCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static int32 getArkSinkSpeed();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static FString getServerIP();


	UFUNCTION(BlueprintCallable, Category = "Cooldown")
	static TArray<float> decreaseCooldown(TArray<float> Cooldown);
	
};
