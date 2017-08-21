//
#pragma once

#include "../Header.h"

#if PLATFORM_WINDOWS
	#include "Windows.h"
	#include "string"
#endif

#include "EngineUtils.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LIB_Cpp.generated.h"


/**
 *	Library exposed to blueprint
 */
UCLASS()
class SINKTHATBOAT_API ULIB_Cpp : public UBlueprintFunctionLibrary {
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

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static bool isWindows();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getMudCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getPitfallCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getSpringCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Constantes")
	static float getTsunamiCooldown();


	/**
	* Add a record in the database
	**/
	UFUNCTION(BlueprintCallable, Category = "Database")
	static void addScore(const FName Name, const int32 Time, const TArray<int32> Scores, const bool hasSinked);

	UFUNCTION(BlueprintCallable, Category = "Cooldown")
	static TArray<float> decreaseCooldown(UPARAM(ref) TArray<float> &Cooldown);
	
};
