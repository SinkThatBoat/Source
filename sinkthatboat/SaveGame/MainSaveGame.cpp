// 2017 . All rights reserved StB 


#include "sinkthatboat.h"
#include "MainSaveGame.h"

UMainSaveGame::UMainSaveGame(const FObjectInitializer & ObjectInit) {
	m_Name = TEXT("");

}


UMainSaveGame* UMainSaveGame::loadSaveGame() {
	UMainSaveGame* const SaveGame = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MainUser"), 0));
	if (SaveGame) {
		return SaveGame;
	}
	return Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));
}


void UMainSaveGame::saveGame() {
	UGameplayStatics::SaveGameToSlot(this, TEXT("MainUser"), 0);
}