// 2017 . All rights reserved StB 

#pragma once

#include "Animation/AnimInstance.h"
#include "ANIM_Animal.generated.h"

class AAnimal;

/**
 *	Base animation of animals
 */
UCLASS()
class SINKTHATBOAT_API UANIM_Animal : public UAnimInstance {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	AAnimal* getAnimal() const;

	virtual void NativeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float m_Speed;
	
};
