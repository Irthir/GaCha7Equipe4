// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlocProcedural.generated.h"

USTRUCT(BlueprintType)
struct FBlocStruct
{
	GENERATED_BODY()
	TArray<uint8> Ligne;
};

USTRUCT(BlueprintType)
struct FObstacleStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	uint8 nDifficulty;
	UPROPERTY(BlueprintReadWrite)
	uint8 nSize;
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<AActor> Obstacle;
};

UCLASS()
class GACHA7EQUIPE4_API ABlocProcedural : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlocProcedural();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	TArray<FBlocStruct> tMap;

	void InitMap();
	
	bool CheckDisponibility(uint8 x, uint8 y, uint8 size);
	
	UFUNCTION(BlueprintCallable)
	void PopulateMap(uint8 nDifficulty);

	UFUNCTION(BlueprintCallable)
	void AddObstacle(uint8 difficulty, uint8 size, TSubclassOf<AActor> Obstacle);

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FObstacleStruct> TObstacleStructs;

	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
