// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "MainPawn.h"


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
		case 1:  _PlayerType = EPlayerEnum::PLAYER_SERVER;   break;
		case 2:  _PlayerType = EPlayerEnum::PLAYER_1;		 break;
		case 3:  _PlayerType = EPlayerEnum::PLAYER_2;		 break;
		default: _PlayerType = EPlayerEnum::PLAYER_SPECTATOR;
		}
	}
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Enable replication for selected variables
void AMainPawn::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPawn, _PlayerType);
}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Set the name on the server
void AMainPawn::setName_Implementation(const FName& Name) {
	_Name = Name;
}

bool AMainPawn::setName_Validate(const FName& Name) {
	return true;
}

/*
	Spawn an animal in the map for this player
	Overridable in blueprint
*/
void AMainPawn::spawnAnimal_Implementation(EAnimalEnum Animal, FTransform Transform, EPlayerEnum Player) {}

/*
	Spawn a trap in the map for this player
	Overridable in blueprint
*/
void AMainPawn::spawnTrap_Implementation(ETrapEnum Trap, FTransform Transform, AActor *Tsunami) {}
