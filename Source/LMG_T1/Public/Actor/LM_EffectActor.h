// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LM_EffectActor.generated.h"

UCLASS()
class LMG_T1_API ALM_EffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALM_EffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
