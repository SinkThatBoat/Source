// 2017 . All rights reserved StB 

#pragma once

#include "../Header.h"
#include "GameFramework/Pawn.h"
#include "MainPawn.generated.h"

UCLASS()
class SINKTHATBOAT_API AMainPawn : public APawn 
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Function that spawns an animal server's side overrided and implemented in blueprint
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animals")
	void spawnAnimal(EAnimalEnum Animal, FTransform Transform);
	void spawnAnimal_Implementation(EAnimalEnum Animal, FTransform Transform);

	//Function that spawns a trap server's side overrided and implemented in blueprint
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Traps")
	void spawnTrap(ETrapEnum Trap, FTransform Transform, AActor *Tsunami);
	void spawnTrap_Implementation(ETrapEnum Trap, FTransform Transform, AActor *Tsunami);

	// Type of player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	EPlayerEnum _PlayerType;

	UFUNCTION(reliable, server, WithValidation)
	int32 SRV_getPlayerNumber() const;
	
};
