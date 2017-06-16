// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "MainPawn.h"


// Sets default values
AMainPawn::AMainPawn() {

 	// Set this pawn to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/*
	Spawn an animal in the map for this player
	Overridable in blueprint
*/
void AMainPawn::spawnAnimal_Implementation(EAnimalEnum Animal, FTransform Transform) {}

/*
	Spawn a trap in the map for this player
	Overridable in blueprint
*/
void AMainPawn::spawnTrap_Implementation(ETrapEnum Trap, FTransform Transform, AActor *Tsunami) {}
