// 版权声明_兴风作浪的李默


#include "UI/HUD/LM_HUD.h"

#include "UI/Widget/LM_UserWidget.h"
#include "UI/WidgetController/OverlayLM_WidgetController.h"

UOverlayLM_WidgetController* ALM_HUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	//如果OverlayWidgetController为空，就创建一个
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayLM_WidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void ALM_HUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is nullptr ,修改下LM_HUD类"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is nullptr ,修改下LM_HUD类"));

	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<ULM_UserWidget>(Widget);

	
	const FWidgetControllerParams WCParams(PC, PS, ASC, AS);
	UOverlayLM_WidgetController* OverlayLM_WidgetController = GetOverlayWidgetController(WCParams);


	OverlayWidget->SetWidgetController(OverlayLM_WidgetController);
	
	Widget->AddToViewport();
}
