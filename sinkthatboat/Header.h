#pragma once

/*
	This file contains all the enum & constant used in C++
*/

//Print to screen macro
#define DEBUG(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT(x)); 
#define ERROR(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,	  TEXT(x));

/**
*	Database options
**/
#define DATABASE_IP			"127.0.0.1"
#define DATABASE_USERNAME	"sinkthatboat"
#define DATABASE_PASSWORD	"Admin"
#define DATABASE_NAME		"sinkthatbase"
#define DATABASE_PORT		3306
#define DATABASE_TABLE		"tb_player"	


/**
*	Constantes
**/

//Server
#define SERVER_IP			"172.16.40.38"

//Arks
#define ARK_LIFE			25000
#define ARK_SINK_SPEED		4

// Animals
#define ELEPHANT_WEIGHT		2500
#define ELEPHANT_SPEED		6
#define ELEPHANT_COOLDOWN	10

#define SEAL_WEIGHT			350
#define SEAL_SPEED			15
#define SEAL_COOLDOWN		3

#define CHICKEN_WEIGHT		100
#define CHICKEN_SPEED		30
#define CHICKEN_COOLDOWN	0.4f

#define PANDA_WEIGHT		850
#define PANDA_SPEED			10
#define PANDA_COOLDOWN		7

// Traps
#define SPRING_LIFE			1
#define SPRING_COOLDOWN		2
#define SPRING_THROW		10000

#define PITFALL_LIFE		10
#define PITFALL_COOLDOWN	30

#define MUD_LIFE			15
#define MUD_COOLDOWN		20

#define TRAP_LIFE			10
#define TRAP_COOLDOWN		30

#define TSUNAMI_COOLDOWN	90





/**
*	ENUMS
**/
UENUM(BlueprintType)
enum class EAnimalEnum : uint8 {
	ANIMAL_ELEPHANT	UMETA(DisplayName = "Elephant"),
	ANIMAL_SEAL		UMETA(DisplayName = "Seal"),
	ANIMAL_PANDA	UMETA(DisplayName = "Panda"),
	ANIMAL_CHICKEN	UMETA(DisplayName = "Chicken")
};

UENUM(BlueprintType)
enum class ETrapEnum : uint8 {
	TRAP_SPRING		UMETA(DisplayName = "Spring"),
	TRAP_MUD		UMETA(DisplayName = "Mud"),
	TRAP_PITFALL	UMETA(DisplayName = "Pitfall"),
	TRAP_TSUNAMI	UMETA(DisplayName = "Tsunami")
};

UENUM(BlueprintType)
enum class EPlayerEnum : uint8 {
	PLAYER_SERVER		UMETA(DisplayName = "Server"),
	PLAYER_1			UMETA(DisplayName = "Player 1"),
	PLAYER_2			UMETA(DisplayName = "Player 2"),
	PLAYER_SPECTATOR	UMETA(DisplayName = "Spectator")
};


