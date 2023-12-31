// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "LM_PlayerState.generated.h"

class UAttributeSet;
/**
 * 
 */
UCLASS()
class LMG_T1_API ALM_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ALM_PlayerState();
	//GAS接口 属性
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const{return  AttributeSet;};

protected:
	//添加GAS的组件
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//添加属性集的组件
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
