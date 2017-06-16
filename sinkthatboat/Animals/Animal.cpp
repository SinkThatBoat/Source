// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Animal.h"
#include "../Trap/Mud.h"

// Sets default values
AAnimal::AAnimal()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_hasDamaged = false;
}

// Called when the game starts or when spawned
void AAnimal::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAnimal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Change the speed if we're in the mud
	setSpeed(_Mud ? _Speed / 2 : _Speed, false);

	//Check if we're in the mud
	if (_Mud) {
		TArray<AActor*> Actors;
		GetOverlappingActors(Actors);

		for (auto& Actor : Actors) {
			AMud *mud = Cast<AMud>(Actor);
			if (mud)
				_Mud = true;
		}
	}

}

// Called to bind functionality to input
void AAnimal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Return if the animal is dead
bool AAnimal::isDead() const {
	return _isDead;
}

//Kill the animal
void AAnimal::kill() {
	_hasDamaged = true;
	stopWalking();
	_isDead = true;

	UWorld* World = GetWorld();

	if (World) {
		FTimerHandle t;
		World->GetTimerManager().SetTimer(t, this, &AAnimal::destroyMe, 0.1f, true);
	}
}


//Stop the animal from walking
void AAnimal::stopWalking() {
	DisableInput(GetWorld()->GetFirstPlayerController());
}

//Set the animal's speed
void AAnimal::setSpeed(int32 Speed, bool applyChange) {
	GetCharacterMovement()->MaxWalkSpeed = Speed * 70;

	if(applyChange)
		_Speed = Speed;
}

//Destroy the animal
void AAnimal::destroyMe() {
	FVector size = GetActorScale3D();
	size.X /= 1.05f;
	size.Y /= 1.05f;
	size.Z /= 1.05f;

	SetActorScale3D(size);

	if (size.X < 0.001f)
		Destroy();
}


//Accessors
int32 AAnimal::getWeight()   const { return _Weight; }
float AAnimal::getCooldown() const { return _Cooldown; }
void  AAnimal::setWeight(int32 Weight) { _Weight = Weight; }
void  AAnimal::setCooldown(float Cooldown) { _Cooldown = Cooldown; }
void  AAnimal::setMud(bool mud) { _Mud = mud; }