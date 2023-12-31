// 版权声明_兴风作浪的李默


#include "Player/LM_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


ALM_PlayerController::ALM_PlayerController()
{
	bReplicates = true;
}

void ALM_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void ALM_PlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
	if (LastActor != ThisActor)
	{
		if (LastActor)
		{
			LastActor->UnhighlightActor();
		}
		if (ThisActor)
		{
			ThisActor->HighlightActor();
		}
	}
}

void ALM_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	//使用断言检查是否存在 InputMappingContext 和 Subsystem 之后，
	//调用 AddMappingContext 函数将 InputMappingContext 添加到 Subsystem 中
	check(LM_InputMappingContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(LM_InputMappingContext, 0);
	}
	//设置鼠标光标
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	//设置输入模式
	FInputModeGameAndUI InputModeDate;
	InputModeDate.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeDate.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeDate);
}

void ALM_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//获取增强输入组件实例
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	//绑定移动函数和输入组件
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ALM_PlayerController::Move);
}

void ALM_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MoveVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveVector.X);
	}
}
