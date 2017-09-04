// All rights reserved StB 

#include "sinkthatboat.h"
#include "LIB_Cpp.h"

float ULIB_Cpp::getSealCooldown() {
	return SEAL_COOLDOWN;
}

float ULIB_Cpp::getPandaCooldown() {
	return PANDA_COOLDOWN;
}

float ULIB_Cpp::getElephantCooldown() {
	return ELEPHANT_COOLDOWN;
}

float ULIB_Cpp::getChickenCooldown() {
	return CHICKEN_COOLDOWN;
}

int32 ULIB_Cpp::getArkSinkSpeed() {
	return ARK_SINK_SPEED;
}

FString ULIB_Cpp::getServerIP() {
	return SERVER_IP;
}

float ULIB_Cpp::getMudCooldown() {
	return MUD_COOLDOWN;
}

float ULIB_Cpp::getPitfallCooldown() {
	return PITFALL_COOLDOWN;
}

float ULIB_Cpp::getSpringCooldown() {
	return SPRING_COOLDOWN;
}

float ULIB_Cpp::getTsunamiCooldown() {
	return TSUNAMI_COOLDOWN;
}

int32 ULIB_Cpp::getElephantPoints() {
	return ELEPHANT_POINTS;
}

int32 ULIB_Cpp::getPandaPoints() {
	return PANDA_POINTS;
}

int32 ULIB_Cpp::getChickenPoints() {
	return CHICKEN_POINTS;
}

int32 ULIB_Cpp::getSealPoints() {
	return SEAL_POINTS;
}

int32 ULIB_Cpp::getWaitCooldown() {
	return WAIT_COOLDOWN;
}

TArray<float> ULIB_Cpp::decreaseCooldown(TArray<float>& Cooldown) {
	for (int32 i = 0; i < Cooldown.Num(); ++i) {
		Cooldown[i] -= 0.05f;
		if (Cooldown[i] < 0)
			Cooldown[i] = 0;
	}
	return Cooldown;
}

bool ULIB_Cpp::isWindows() {
	return PLATFORM_WINDOWS;
}

	
void ULIB_Cpp::addScore(
	const FName& Name,
	const int32& Score,
	const bool hasSinked
) {
#if PLATFORM_WINDOWS
		//Call another program to add player in the db
		const FString s = FString("start ") + DATABASE_APP + TEXT(" ") + Name.ToString() + TEXT(" ") + FString::FromInt(Score); 
		const std::string param(TCHAR_TO_UTF8(*s));
		system(param.c_str());
#endif
}



void ULIB_Cpp::savePlayerName(const FName& Name) {
	UMainSaveGame* const SaveGame = UMainSaveGame::loadSaveGame();
	if (SaveGame) {
		SaveGame->m_Name = Name;
		SaveGame->saveGame();
	}
}


FName ULIB_Cpp::loadPlayerName() {
	UMainSaveGame* const SaveGame = UMainSaveGame::loadSaveGame();
	if (SaveGame) {
		return SaveGame->m_Name;
	}
	return TEXT("");
}

FName ULIB_Cpp::getAvailablePseudo() {
	// Fill the array with the file "Pseudos.arr"
	const TArray<FName> Names = {
		#include "Pseudos.arr"
	};

	// Choose a random name
	const int32 RandomNum = FMath::RandRange(0, Names.Num() - 1);
	return Names[RandomNum];
}