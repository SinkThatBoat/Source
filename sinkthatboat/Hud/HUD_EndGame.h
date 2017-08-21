// 2017 . All rights reserved StB 

#pragma once

#include "Blueprint/UserWidget.h"
#include "HUD_EndGame.generated.h"

/**
 *	HUD displayed at the end of the game
 */
UCLASS()
class SINKTHATBOAT_API UHUD_EndGame : public UUserWidget {
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void setWinnerName(const FName& Name);
	
	UFUNCTION(BlueprintCallable)
	void setWinnerScore(const int32& Score);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Winner")
	FName m_WinnerName;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Winner")
	int32 m_WinnerScore;



};
