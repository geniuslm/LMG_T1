// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "Charactor/LmCharacter_Base.h"
#include "LM_Character.generated.h"

/**
 * 
 */
UCLASS()
class LMG_T1_API ALM_Character : public ALmCharacter_Base
{
	GENERATED_BODY()
public:
	ALM_Character();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
    void InitAbilityActorInfo();	
};
