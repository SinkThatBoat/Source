// 2017 . All rights reserved StB 

#pragma once

#include "../Ark/Ark.h"
#include "../Header.h"
#include "GameFramework/Character.h"
#include "Animal.generated.h"


class AMud;

UCLASS()
class SINKTHATBOAT_API AAnimal : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//If the animal is dead
	UFUNCTION(BlueprintCallable)
		bool isDead() const;

	//Kill the animal
	UFUNCTION(BlueprintCallable)
		void kill();

	//Stop the movement of the animal
	UFUNCTION(BlueprintCallable)
		void stopWalking();

	//Set the walking's speed
	UFUNCTION(BlueprintCallable)
		void setSpeed(const int32 Speed, const bool applyChange = true);

	//Get weight
	UFUNCTION(BlueprintCallable)
		int32 getWeight() const;

	//Set weight
	UFUNCTION(BlueprintCallable)
		void setWeight(const int32 Weight);

	//Get Cooldown
	UFUNCTION(BlueprintCallable)
		float getCooldown() const;

	//Set Cooldown
	UFUNCTION(BlueprintCallable)
		void setCooldown(const float Cooldown);

	UFUNCTION()
		void destroyMe();

	UFUNCTION()
		void setMud(bool mud);


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
		EPlayerEnum _OwningPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
		AArk *_Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool _hasDamaged;

	UPROPERTY()
		bool _isDead;
	UPROPERTY()
		int32 _Weight;
	UPROPERTY()
		float _Cooldown;

	UPROPERTY()
		bool _Mud;

	UPROPERTY()
		int32 _Speed;
};