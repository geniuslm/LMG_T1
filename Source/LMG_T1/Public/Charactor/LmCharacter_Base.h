// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "LmCharacter_Base.generated.h"
//设置 Abstract 抽象类 可以不能被实例化
UCLASS(Abstract)
class LMG_T1_API ALmCharacter_Base : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// 它的构造函数
	ALmCharacter_Base();
	//GAS接口 属性
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const{return  AttributeSet;};
	

protected:
	// 当游戏开始或者角色被生成时调用
	virtual void BeginPlay() override;

	//添加武器的 骨骼网格体组件
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	//添加GAS的组件
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//添加属性集的组件
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
