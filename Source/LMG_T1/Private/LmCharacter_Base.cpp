// 版权声明_兴风作浪的李默


#include "LmCharacter_Base.h"

// Sets default values
ALmCharacter_Base::ALmCharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALmCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALmCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALmCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

