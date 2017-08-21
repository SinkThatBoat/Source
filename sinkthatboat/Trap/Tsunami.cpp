// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Tsunami.h"

void ATsunami::spawn(FVector location) {
	SetActorLocation(location);
	
	UWorld *World = GetWorld();
	if (World) {
		FTimerHandle t;
		World->GetTimerManager().SetTimer(t, this, &ATsunami::moveForward, 0.01f, true);
	}

}

void ATsunami::moveForward() {
	FVector location = GetActorLocation();

	location.X += 100;

	SetActorLocation(location, true);

	TArray<AActor*> Actors;
	
	//DEBUG("Hit");

	GetOverlappingActors(Actors);

	for (auto& Actor : Actors) {
		AAnimal *Animal = Cast<AAnimal>(Actor);
		if (Animal) {
			FVector l = Animal->GetActorLocation();
			l.Z += 30;
			l.X += 110;
			Animal->SetActorLocation(l);
			Animal->GetMovementComponent()->StopMovementImmediately();
		}
	}
}