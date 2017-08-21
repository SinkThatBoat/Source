// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Trap.h"


// Sets default values
ATrap::ATrap() {
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATrap::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ATrap::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}
