// 版权声明_兴风作浪的李默


#include "Player/LM_PlayerState.h"

#include "AbilitySystem/LM_AbilitySystemComponent.h"
#include "AbilitySystem/LM_AttributeSet.h"

ALM_PlayerState::ALM_PlayerState()
{
	//创建GAS组件 和属性集 并且设置为可复制
	AbilitySystemComponent = CreateDefaultSubobject<ULM_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<ULM_AttributeSet>(TEXT("AttributeSet"));

	NetUpdateFrequency = 100.f;
	
}

//实现GAS接口 返回GAS组件
UAbilitySystemComponent* ALM_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
