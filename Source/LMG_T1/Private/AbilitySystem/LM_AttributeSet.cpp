// 版权声明_兴风作浪的李默


#include "AbilitySystem/LM_AttributeSet.h"


#include "Net/UnrealNetwork.h"

ULM_AttributeSet::ULM_AttributeSet()
{
	InitHealth(60.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
	
}

void ULM_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULM_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULM_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULM_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULM_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}


void ULM_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULM_AttributeSet, Health, OldHealth);
}

void ULM_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULM_AttributeSet, MaxHealth, OldMaxHealth);
}

void ULM_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULM_AttributeSet, Mana, OldMana);
}

void ULM_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULM_AttributeSet, MaxMana, OldMaxMana);
}
