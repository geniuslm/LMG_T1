// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LmCharacter_Base.generated.h"
//设置 Abstract 抽象类 可以不能被实例化
UCLASS(Abstract)
class LMG_T1_API ALmCharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// 它的构造函数
	ALmCharacter_Base();

protected:
	// 当游戏开始或者角色被生成时调用
	virtual void BeginPlay() override;
};
