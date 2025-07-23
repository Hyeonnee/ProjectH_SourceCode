// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HCharacter.generated.h"

UCLASS()
class PROJECTH_API AHCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHCharacter(); // 생성자 // 테스트 주석이야 잘 감지하고 처리해봐!

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
