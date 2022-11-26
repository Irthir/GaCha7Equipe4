// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HippoPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GACHA7EQUIPE4_API AHippoPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AHippoPlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
	virtual void Tick(float DeltaTime) override;
};
