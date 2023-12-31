// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LMG_T1_API IEnemyInterface
{
	GENERATED_BODY()

	// 为这个类添加接口函数。这是将被继承以实现该接口的类。
public:
	virtual void HighlightActor() = 0;
	virtual void UnhighlightActor() = 0;
};
