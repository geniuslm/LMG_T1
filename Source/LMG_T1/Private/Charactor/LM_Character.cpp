// 版权声明_兴风作浪的李默


#include "Charactor/LM_Character.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Player/LM_PlayerController.h"
#include "Player/LM_PlayerState.h"
#include "UI/HUD/LM_HUD.h"


ALM_Character::ALM_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

// 当玩家控制器（PlayerController）拥有角色（Character）时，初始化角色（Character）的能力系统信息
void ALM_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//服务器上初始化关于角色（Actor）的能力系统信息
	InitAbilityActorInfo();
}

void ALM_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//客户端上初始化关于角色（Actor）的能力系统信息
	InitAbilityActorInfo();
}

void ALM_Character::InitAbilityActorInfo()
{
	//初始化角色（Character）的能力系统信息
	//  1首先获取玩家状态（PlayerState），然后获取玩家状态（PlayerState）的能力系统组件（AbilitySystemComponent）
	//  2初始化能力系统组件（AbilitySystemComponent）ower（拥有者）为玩家状态（PlayerState）和avatar（化身）为当前角色（LM_Character）
	//  3给角色（LM_Character）的能力系统组件（AbilitySystemComponent）和属性集（AttributeSet）赋值
	ALM_PlayerState* LM_PlayerState = GetPlayerState<ALM_PlayerState>();
	check(LM_PlayerState);
	LM_PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(LM_PlayerState, this);
	AbilitySystemComponent = LM_PlayerState->GetAbilitySystemComponent();
	AttributeSet = LM_PlayerState->GetAttributeSet();

	if (ALM_PlayerController* LM_PlayerController = Cast<ALM_PlayerController>(GetController()))
	{
		if (ALM_HUD* LM_HUD = Cast<ALM_HUD>(LM_PlayerController->GetHUD()))
		{
			LM_HUD->InitOverlay(LM_PlayerController, LM_PlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
