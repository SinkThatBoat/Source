// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Mud.h"


AMud::AMud() {

}

// Called when the game starts or when spawned
void AMud::BeginPlay() {
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World) {
		// Set timer to reduce the size of the mud
		FTimerHandle t;
		World->GetTimerManager().SetTimer(t, this, &AMud::minimize, 0.1f, true);
	}

}

// Called every frame
void AMud::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	// Slow the animals
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (auto& Actor : Actors) {
		AAnimal *Animal = Cast<AAnimal>(Actor);
		if (Animal) {
			Animal->setMud(true);
		}
	}

}

//Reduce the size of the mud
void AMud::minimize() {
	FVector v = GetActorScale3D();

	v.X /= 1.01;
	v.Y /= 1.01;
	v.Z /= 1.01;

	if (v.X < 0.1)
		Destroy();
}