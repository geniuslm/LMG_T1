// 版权声明_兴风作浪的李默


#include "Actor/LM_EffectActor.h"

// Sets default values
ALM_EffectActor::ALM_EffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALM_EffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALM_EffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

