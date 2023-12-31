// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "Charactor/LmCharacter_Base.h"
#include "Interaction/EnemyInterface.h"
#include "Enemy_Character.generated.h"

/**
 * 
 */
UCLASS()
class LMG_T1_API AEnemy_Character : public ALmCharacter_Base, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemy_Character();
	
	/** 实现 IEnemyInterface */
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	/** 实现 IEnemyInterface End */

protected:
	virtual void BeginPlay() override;
	
};
