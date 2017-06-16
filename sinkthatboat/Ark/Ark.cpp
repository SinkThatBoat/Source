// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Ark.h"


// Sets default values
AArk::AArk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set the ark life
	_MaxLife = ARK_LIFE;
	_Life    = _MaxLife;

}

// Called when the game starts or when spawned
void AArk::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


/**
*	Receive damages
*	@param Damages Damages received
*	@return Is dead
**/
bool AArk::receiveDamages(int32 Damages) {
	_Life -= Damages;
	
	if (_Life <= 0) {
		_Life = 0;
		return true;
	}

	return false;
}