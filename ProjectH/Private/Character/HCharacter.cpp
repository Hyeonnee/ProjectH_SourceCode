// Fill out your copyright notice in the Description page of Project Settings.
#include "ProjectH/Public/Character/HCharacter.h"

// Sets default values
AHCharacter::AHCharacter()
{
 	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Temporary debug log
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
}

// Called when the game starts or when spawned
void AHCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

