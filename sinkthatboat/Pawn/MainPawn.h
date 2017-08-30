// 2017 . All rights reserved StB 

#pragma once

#include "Enums.h"
#include "Macros.h"
#include "Header.h"
#include "SaveGame/MainSaveGame.h"
#include "Libs/LIB_Cpp.h"
#include "UnrealNetwork.h"
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

	/**
	 *	Add points to the player
	 **/
	 UFUNCTION(BlueprintCallable, Server, reliable, WithValidation)
	 void Server_addPoints(const int32& Points);

	 /**
	 *	Called when the game ends, and one ark sunk
	 **/
	 UFUNCTION(BlueprintCallable, Category = "Gameplay")
	 void OnEndGame(const int& OurArkLife);
	 
	 /**
	  *	Called when this pawn win the game
	  **/
	 UFUNCTION(BlueprintCallable)
	 void won();

	 UFUNCTION(BlueprintCallable, Category = "Points")
	 int32 getScore() const;

protected:
	UFUNCTION(Server, reliable, WithValidation, BlueprintCallable)
	void Server_setName(const FName& Name);

	// Type of player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", Replicated)
	EPlayerEnum m_PlayerType;
	
	//The name of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name", Replicated)
	FName m_Name;


	// Score handling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points", Replicated)
	int32 m_Score;
};
