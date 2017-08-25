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
	/**
	 *	Constructor
	 **/
	UMainSaveGame(const FObjectInitializer & ObjectInit);

	/**
	 * Data
	 **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName m_Name;
	
public:
	/**
	 * @return A loaded save game 
	 **/
	UFUNCTION()
	static UMainSaveGame* loadSaveGame();
	
	/**
	 * Save this save to disk
	 **/
	UFUNCTION()
	void saveGame();

};