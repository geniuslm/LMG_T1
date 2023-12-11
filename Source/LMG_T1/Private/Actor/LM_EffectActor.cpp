// 版权声明_兴风作浪的李默


#include "Actor/LM_EffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/LM_AttributeSet.h"
#include "Components/SphereComponent.h"


ALM_EffectActor::ALM_EffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void ALM_EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                const FHitResult& SweepResult)
{
	//如果OtherActor实现了ILM_AbilitySystemInterface接口
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		//todo:这里需要修改，不应该直接获取属性集合，而是应该通过GameplayEffect来修改属性
		//获取AbilitySystemComponent里面的属性集合
		const ULM_AttributeSet* LM_AttributeSet = Cast<ULM_AttributeSet>(
			ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(ULM_AttributeSet::StaticClass()));
		ULM_AttributeSet* MutableLM_AttributeSet = const_cast<ULM_AttributeSet*>(LM_AttributeSet);
		MutableLM_AttributeSet->SetHealth(LM_AttributeSet->GetHealth() + 20.f);
		Destroy();
	}
}

void ALM_EffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


void ALM_EffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ALM_EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ALM_EffectActor::EndOverlap);
}
