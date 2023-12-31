// 版权声明_兴风作浪的李默


#include "Charactor/Enemy_Character.h"

#include "AbilitySystem/LM_AbilitySystemComponent.h"
#include "AbilitySystem/LM_AttributeSet.h"
#include "LMG_T1/LMG_T1.h"


AEnemy_Character::AEnemy_Character()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	//创建GAS组件 并且设置为可复制
	AbilitySystemComponent = CreateDefaultSubobject<ULM_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	//设置属性集组件
	AttributeSet = CreateDefaultSubobject<ULM_AttributeSet>(TEXT("AttributeSet"));
}

void AEnemy_Character::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemy_Character::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AEnemy_Character::BeginPlay()
{
	Super::BeginPlay();

	//初始化属性集组件
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
