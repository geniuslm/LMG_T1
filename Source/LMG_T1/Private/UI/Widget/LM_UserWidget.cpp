// 版权声明_兴风作浪的李默


#include "UI/Widget/LM_UserWidget.h"


void ULM_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
	
}
