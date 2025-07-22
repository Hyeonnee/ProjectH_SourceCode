#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HAnimInstanceBase.generated.h"

class AHCharacter;

/**
 * 베이스 애니메이션 인스턴스 클래스
 * 캐릭터의 애니메이션 로직을 처리하는 C++ 기반 클래스
 */
UCLASS()
class PROJECTH_API UHAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	UHAnimInstanceBase(); //생성자

protected:
	// 애니메이션에서 사용할 캐릭터 레퍼런스
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	AHCharacter* OwnerCharacter;

	// 기본 이동 관련 변수들
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsMoving;

	// 방향 관련 변수들
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float Direction;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FVector Velocity;

protected:
	// 애니메이션 업데이트 함수들
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

private:
	// 내부 계산 함수들
	void UpdateMovementVariables();
	void UpdateCharacterReference();
};