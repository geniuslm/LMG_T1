// 版权声明_兴风作浪的李默


#include "Charactor/LmCharacter_Base.h"

 
ALmCharacter_Base::ALmCharacter_Base()
{
	//不要每帧调用Tick函数
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ALmCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
}


