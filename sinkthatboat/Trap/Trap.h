// 2017  All rights reserved StB 

#pragma once

#include "../Header.h"
#include "../Animals/Animal.h"
#include "GameFramework/Actor.h"
#include "Trap.generated.h"

UCLASS()
class SINKTHATBOAT_API ATrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void freePlace();
	void freePlace_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent *_Mesh;
	
};
