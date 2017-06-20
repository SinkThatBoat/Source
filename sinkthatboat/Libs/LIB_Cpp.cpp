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

TArray<float> ULIB_Cpp::decreaseCooldown(TArray<float> Cooldown) {
	for (int32 i = 0; i < Cooldown.Num(); ++i) {
		Cooldown[i] -= 0.05f;
		if (Cooldown[i] < 0)
			Cooldown[i] = 0;
	}
	return Cooldown;
}



<<<<<<< HEAD
void ULIB_Cpp::addScore(FName name, int32 Score) {
	
=======
void ULIB_Cpp::addScore(
	FName Name,
	int32 Score
) {
#if __WINDOWS__
	//Call another program to add player in the db
	FString s = DATABASE_APP + FString(" ") + Name.ToString() + FString("¢") + FString::FromInt(Score);
	std::string param(TCHAR_TO_UTF8(*s));
	system(param.c_str());
#endif
>>>>>>> 064c64f106598b654aaab184c3313971bbe9b7ec
}
