// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "MainPawn.h"
#include "SaveGame/MainSaveGame.h"
#include "Libs/LIB_Cpp.h"

// Sets default values
AMainPawn::AMainPawn() {

 	// Set this pawn to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

	// Make sure that we're replicating this actor
	bReplicates = true;
}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay() {
	Super::BeginPlay();
	
	//Set the replicated var server side
	if (Role == ROLE_Authority) {
		switch (GetWorld()->GetAuthGameMode()->GetNumPlayers()) {
		case 1:  m_PlayerType = EPlayerEnum::PLAYER_SERVER;   break;
		case 2:  m_PlayerType = EPlayerEnum::PLAYER_1;		 break;
		case 3:  m_PlayerType = EPlayerEnum::PLAYER_2;		 break;
		default: m_PlayerType = EPlayerEnum::PLAYER_SPECTATOR;
		}
	}

	// Set the name of the player from the client to the server
	if (Role != ROLE_Authority) {
		const FName Name = ULIB_Cpp::loadPlayerName();
		Server_setName(Name);
	}
}

// Called every frame
void AMainPawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

//Enable replication for selected variables
void AMainPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPawn, m_PlayerType);
	DOREPLIFETIME(AMainPawn, m_Name);
}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Set the name on the server
void AMainPawn::Server_setName_Implementation(const FName& Name) {
	m_Name = Name;
}

bool AMainPawn::Server_setName_Validate(const FName& Name) {
	return true;
}
