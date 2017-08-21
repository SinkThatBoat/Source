// 2017 . All rights reserved StB 

#pragma once

#include "Enums.h"
#include "Macros.h"
#include "UnrealNetwork.h"
#include "Header.h"
#include "GameFramework/Pawn.h"
#include "MainPawn.generated.h"

UCLASS()
class SINKTHATBOAT_API AMainPawn : public APawn  {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties 
	AMainPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Set up the replication
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Function that spawns an animal server's side overrided and implemented in blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Animals")
	void spawnAnimal(const EAnimalEnum Animal, const FTransform& Transform, const EPlayerEnum Player);

	//Function that spawns a trap server's side overrided and implemented in blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Traps")
	void spawnTrap(const ETrapEnum Trap, const FTransform& Transform, AActor *Tsunami);

protected:
	UFUNCTION(Server, reliable, WithValidation, BlueprintCallable)
	void Server_setName(const FName& Name);

	// Type of player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", Replicated)
	EPlayerEnum m_PlayerType;
	
	//The name of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name", Replicated)
	FName m_Name;


};
