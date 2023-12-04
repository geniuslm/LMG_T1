// 版权声明_兴风作浪的李默


#include "Charactor/LM_Character.h"

#include "GameFramework/CharacterMovementComponent.h"


ALM_Character::ALM_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.0f,400.0f,0.0f);
	GetCharacterMovement()->bConstrainToPlane=true;
	GetCharacterMovement()->bSnapToPlaneAtStart=true;

	bUseControllerRotationPitch=false;
	bUseControllerRotationYaw=false;
	bUseControllerRotationRoll=false;
}
