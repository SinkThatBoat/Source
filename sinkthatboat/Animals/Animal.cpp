// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Animal.h"
#include "Trap/Mud.h"

// Sets default values
AAnimal::AAnimal() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_hasDamaged = false;

	// Improve network performance by disabling replication
	bReplicateMovement = false;
	bReplicates = false;
}

// Called when the game starts or when spawned
void AAnimal::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AAnimal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Change the speed if we're in the mud
	setSpeed(m_isInMud ? m_Speed / 2.f : m_Speed, false);

	//Check if we're in the mud
	/*if (m_isInMud) {
		TArray<AActor*> Actors;
		GetOverlappingActors(Actors);

		for (auto& Actor : Actors) {
			AMud *mud = Cast<AMud>(Actor);
			if (!mud)
				m_isInMud = false;
		}
	}*/

}

// Called to bind functionality to input
void AAnimal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Return if the animal is dead
bool AAnimal::isDead() const {
	return m_isDead;
}

//Kill the animal
void AAnimal::kill() {
	m_hasDamaged = true;
	stopWalking();
	m_isDead = true;

	UWorld* World = GetWorld();

	if (World) {
		FTimerHandle t;
		World->GetTimerManager().SetTimer(t, this, &AAnimal::destroyMe, 0.1f, true);
	}
}


//Stop the animal from walking
void AAnimal::stopWalking() {
	//DisableInput(GetWorld()->GetFirstPlayerController());
	GetCharacterMovement()->MaxWalkSpeed = 0;
}

//Set the animal's speed
void AAnimal::setSpeed(int32 Speed, bool applyChange) {
	GetCharacterMovement()->MaxWalkSpeed = Speed * 70;
	DEBUG_INT(Speed);
	if(applyChange) {
		m_Speed = Speed;
	}
}

//Destroy the animal
void AAnimal::destroyMe() {
	FVector size = GetActorScale3D();
	size.X /= 1.01f;
	size.Y /= 1.01f;
	size.Z /= 1.01f;

	SetActorScale3D(size);

	if (size.X < 0.001f)
		Destroy();
}


//Accessors
int32 AAnimal::getWeight()   const { return m_Weight; }
float AAnimal::getCooldown() const { return m_Cooldown; }
void  AAnimal::setWeight(int32 Weight) { m_Weight = Weight; }
void  AAnimal::setCooldown(float Cooldown) { m_Cooldown = Cooldown; }
void  AAnimal::setMud(bool mud) { m_isInMud = mud; }