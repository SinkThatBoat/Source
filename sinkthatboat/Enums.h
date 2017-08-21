#pragma once
/**
*	ENUMS
**/

UENUM(BlueprintType)
enum class EPlayerEnum : uint8 {
	PLAYER_SERVER		UMETA(DisplayName = "Server"),
	PLAYER_1			UMETA(DisplayName = "Player 1"),
	PLAYER_2			UMETA(DisplayName = "Player 2"),
	PLAYER_SPECTATOR	UMETA(DisplayName = "Spectator")
};

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


