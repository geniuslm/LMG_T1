// 版权声明_兴风作浪的李默


#include "Charactor/LmCharacter_Base.h"

 
ALmCharacter_Base::ALmCharacter_Base()
{
	//不要每帧调用Tick函数
	PrimaryActorTick.bCanEverTick = false;
	//创建武器骨骼网格组件
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	//把武器骨骼网格组件附加到角色的插槽上
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	//设置武器骨骼网格体没有碰撞
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);



}

UAbilitySystemComponent* ALmCharacter_Base::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ALmCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
}


