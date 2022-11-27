// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlocProcedural.generated.h"

USTRUCT(BlueprintType)
struct FBlocStruct
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	TArray<int32> Ligne;
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
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> Categorie;
};

UCLASS(BlueprintType)
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
	int32 nTailleBloc = 10;


	void InitMap();
	
	bool CheckDisponibility(uint8 x, uint8 y, uint8 size);

	void InsertObstacle(uint8 nX, uint8 nY, int32 nIndexObstacle, uint8 nSize);
	
	UFUNCTION(BlueprintCallable)
	void PopulateMap(int32 nDifficulty, FString TypeObstacle);

	UFUNCTION(BlueprintCallable)
	void AddObstacle(uint8 difficulty, uint8 size, TSubclassOf<AActor> Obstacle, TArray<FString> tCategorie);

	UFUNCTION(BlueprintCallable)
	int32 GetSize(FObstacleStruct obstacleStruct)
	{
		return obstacleStruct.nSize;
	}

	UFUNCTION(BlueprintCallable)
	TSubclassOf<AActor> GetBP(FObstacleStruct obstacleStruct)
	{
		return obstacleStruct.Obstacle;
	}

	UFUNCTION(BlueprintCallable)
	TArray<int32> GetLigne(FBlocStruct BlocStruct)
	{
		return BlocStruct.Ligne;
	}


	UFUNCTION(BlueprintCallable)
	TArray<FBlocStruct> GetTMap()
	{
		return tMap;
	}
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FObstacleStruct> TObstacleStructs;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FBlocStruct> tMap;

	
	UPROPERTY(BlueprintReadWrite)
	FString Categorie;
};