// 版权声明_兴风作浪的李默

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LM_EffectActor.generated.h"

class USphereComponent;

UCLASS()
class LMG_T1_API ALM_EffectActor : public AActor
{
	GENERATED_BODY()

public:
	ALM_EffectActor();
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                       const FHitResult& SweepResult);
	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	//添加一个球形碰撞体
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
	//添加静态网格体组件 Mesh
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
