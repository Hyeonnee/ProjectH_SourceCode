#include "Animation/HAnimInstanceBase.h"
#include "Character/HCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UHAnimInstanceBase::UHAnimInstanceBase()
{
	// 기본값 초기화
	OwnerCharacter = nullptr;
	Speed = 0.0f;
	bIsInAir = false;
	bIsMoving = false;
	Direction = 0.0f;
	Velocity = FVector::ZeroVector;
}

void UHAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	// 캐릭터 레퍼런스 설정
	UpdateCharacterReference();
}

void UHAnimInstanceBase::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	
	// 캐릭터 레퍼런스가 유효하지 않으면 다시 시도
	if (!OwnerCharacter)
	{
		UpdateCharacterReference();
	}
	
	// 캐릭터가 유효할 때만 애니메이션 변수 업데이트
	if (OwnerCharacter)
	{
		UpdateMovementVariables();
	}
}

void UHAnimInstanceBase::UpdateMovementVariables()
{
	if (!OwnerCharacter)
	{
		return;
	}

	// 움직임 컴포넌트 가져오기 (읽기 전용)
	const UCharacterMovementComponent* MovementComponent = OwnerCharacter->GetCharacterMovement();
	if (!MovementComponent)
	{
		return;
	}

	// 기본 이동 변수들 업데이트
	Velocity = OwnerCharacter->GetVelocity();
	Speed = Velocity.Size();
	bIsMoving = Speed > 3.0f; // 3 유닛 이상일 때 움직이는 것으로 판단
	bIsInAir = MovementComponent->IsFalling();

	// 방향 계산 (캐릭터의 전방 벡터와 이동 방향의 각도)
	if (bIsMoving)
	{
		FVector Forward = OwnerCharacter->GetActorForwardVector();
		FVector MovementDirection = Velocity.GetSafeNormal();
		
		// 내적을 사용하여 전후방 움직임 판단
		float DotProduct = FVector::DotProduct(Forward, MovementDirection);
		
		// 외적을 사용하여 좌우 움직임 판단
		FVector CrossProduct = FVector::CrossProduct(Forward, MovementDirection);
		
		// -180 ~ 180도 범위의 각도 계산
		Direction = UKismetMathLibrary::DegAtan2(CrossProduct.Z, DotProduct);
	}
	else
	{
		Direction = 0.0f;
	}
}

void UHAnimInstanceBase::UpdateCharacterReference()
{
	// 폰을 HCharacter로 캐스팅하여 레퍼런스 설정
	APawn* OwnerPawn = TryGetPawnOwner();
	OwnerCharacter = Cast<AHCharacter>(OwnerPawn);
}