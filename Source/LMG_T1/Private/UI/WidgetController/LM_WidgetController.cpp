// 版权声明_兴风作浪的李默


#include "UI/WidgetController/LM_WidgetController.h"

void ULM_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void ULM_WidgetController::BroadcastInitialValues()
{
	
}

void ULM_WidgetController::BindCallbacksToDependencies()
{
}
