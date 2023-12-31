// 版权声明_兴风作浪的李默


#include "UI/WidgetController/OverlayLM_WidgetController.h"

#include "AbilitySystem/LM_AttributeSet.h"

void UOverlayLM_WidgetController::BroadcastInitialValues()
{
	const ULM_AttributeSet* LM_Attributes = Cast<ULM_AttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(LM_Attributes->GetHealth());
	OnMaxHealthChanged.Broadcast(LM_Attributes->GetMaxHealth());
	OnManaChanged.Broadcast(LM_Attributes->GetMana());
	OnMaxManaChanged.Broadcast(LM_Attributes->GetMaxMana());
}

void UOverlayLM_WidgetController::BindCallbacksToDependencies()
{
	const ULM_AttributeSet* LM_Attributes = Cast<ULM_AttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LM_Attributes->GetHealthAttribute()).AddUObject(this, &UOverlayLM_WidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LM_Attributes->GetMaxHealthAttribute()).AddUObject(this, &UOverlayLM_WidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LM_Attributes->GetManaAttribute()).AddUObject(this, &UOverlayLM_WidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LM_Attributes->GetMaxManaAttribute()).AddUObject(this, &UOverlayLM_WidgetController::MaxManaChanged);
}

void UOverlayLM_WidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayLM_WidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayLM_WidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayLM_WidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
