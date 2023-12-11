// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LM_WidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class LMG_T1_API ULM_WidgetController : public UObject
{
	GENERATED_BODY()

protected:
	//设置指针 指向 playerController playerState AbulitySystemComponent AttributeSet
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
