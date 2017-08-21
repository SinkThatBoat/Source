// 2017 . All rights reserved StB 

#pragma once

#include "../Header.h"
#include "GameFramework/Actor.h"
#include "Ark.generated.h"

UCLASS()

class SINKTHATBOAT_API AArk : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// When the ark receive damages
	UFUNCTION(BlueprintCallable)
	bool receiveDamages(int32 Damages);

	//The maximum life of the ark
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 _MaxLife;

	//The maximum life of the ark
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay")
	int32 _Life;

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void displayEndGameHUD(); 

	
	
};
