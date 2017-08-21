// 2017 . All rights reserved StB 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MainSaveGame.generated.h"

/**
 *	Used to store data across levels
 */
UCLASS()
class SINKTHATBOAT_API UMainSaveGame : public USaveGame {
	GENERATED_BODY()
	
public:

	UMainSaveGame(const FObjectInitializer & ObjectInit);

	/**
	 * Data
	 **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName m_Name;
	
public:
	UFUNCTION()
	static UMainSaveGame* loadSaveGame();
	
	UFUNCTION()
	void saveGame();

};
