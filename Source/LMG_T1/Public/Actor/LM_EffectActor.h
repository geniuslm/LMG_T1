// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LM_EffectActor.generated.h"

class USphereComponent;

UCLASS()
class LMG_T1_API ALM_EffectActor : public AActor
{
	GENERATED_BODY()

public:
	ALM_EffectActor();
	
protected:
	virtual void BeginPlay() override;

private:

};
