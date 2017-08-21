// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "HUD_EndGame.h"


void UHUD_EndGame::NativeConstruct() {
	Super::NativeConstruct();
}




void UHUD_EndGame::setWinnerName(const FName& Name) {
	m_WinnerName = Name;
}


void UHUD_EndGame::setWinnerScore(const int32& Score) {
	m_WinnerScore = Score;
}