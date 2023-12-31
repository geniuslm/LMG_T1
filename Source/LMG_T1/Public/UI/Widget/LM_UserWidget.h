// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LM_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class LMG_T1_API ULM_UserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
