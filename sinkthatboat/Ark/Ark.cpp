// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Ark.h"


// Sets default values
AArk::AArk() {
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

	//Set the ark life
	_MaxLife = ARK_LIFE;
	_Life    = _MaxLife;
	isGameOver = false;

}

// Called when the game starts or when spawned
void AArk::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AArk::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}


/**
*	Receive damages
*	@param Damages Damages received
*	@return Is dead
**/
bool AArk::receiveDamages(int32 Damages) {
	if (!isGameOver) {
		_Life -= Damages;
	
		if (_Life <= 0) {
			_Life = 0;

			// Display the end game hud
			displayEndGameHUD();

			return true;
		}
	}

	return false;
}


bool AArk::isSunk() const {
	return _Life <= 0;
}

void AArk::OnEndGame(const int32& OurArkLife) {
	isGameOver = true;
}