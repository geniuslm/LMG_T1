// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "LM_AttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LMG_T1_API ULM_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	ULM_AttributeSet();
	virtual  void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing= OnRep_Health, BlueprintReadOnly, Category = "Vital AttributeSet")
	FGameplayAttributeData Health;

	//设置最大生命值和他的函数
	UPROPERTY( ReplicatedUsing = OnRep_MaxHealth, BlueprintReadOnly, Category = "Vital AttributeSet")
	FGameplayAttributeData MaxHealth;

	//设置法力值 和最大法力值和他们的应答函数
	UPROPERTY(ReplicatedUsing = OnRep_Mana, BlueprintReadOnly, Category = "Vital AttributeSet")
	FGameplayAttributeData Mana;

	UPROPERTY(ReplicatedUsing = OnRep_MaxMana, BlueprintReadOnly, Category = "Vital AttributeSet")
	FGameplayAttributeData MaxMana;
	

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
