// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"


#include "LM_HUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayLM_WidgetController;
class ULM_UserWidget;
/**
 * 
 */
UCLASS()
class LMG_T1_API ALM_HUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ULM_UserWidget> OverlayWidget;

	UFUNCTION()
	UOverlayLM_WidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	UFUNCTION()
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:
	UPROPERTY()
	TObjectPtr<UOverlayLM_WidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ULM_UserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayLM_WidgetController> OverlayWidgetControllerClass;
};
