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



void ULIB_Cpp::addScore(
	FName Name,
	int32 Score
) {
	
	//Var
	MYSQL mysql;

	//Init MySQL
	mysql_init(&mysql);

	//Set the options
	mysql_options(
		&mysql,
		mysql_option::MYSQL_READ_DEFAULT_GROUP, 
		"option"
	);

	//Connect to SinkThatBase
	if (mysql_real_connect(
			&mysql,
			DATABASE_IP,
			DATABASE_USERNAME,
			DATABASE_PASSWORD,
			DATABASE_NAME,
			DATABASE_PORT,
			NULL,
			0
	)) {
		//Prepare the query
		FString Query = "INSERT INTO " + FString(DATABASE_TABLE) + " VALUES (NULL, " + Name.ToString() + ", " + FString::FromInt(Score) + ");";
		std::string s(TCHAR_TO_UTF8(*Query));


		//Add the user in the detabase
		mysql_query(&mysql, s.c_str());
		
		//Close the connexion
		mysql_close(&mysql);
	}


}
