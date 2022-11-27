// Fill out your copyright notice in the Description page of Project Settings.


#include "BlocProcedural.h"

// Sets default values
ABlocProcedural::ABlocProcedural()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABlocProcedural::BeginPlay()
{
	Super::BeginPlay();
	InitMap();
}

// Initialisation de la Map d'un bloc.
void ABlocProcedural::InitMap()
{
	FBlocStruct bloc;
	bloc.Ligne.Init(0,10);
	tMap.Init(bloc,10);
}

bool ABlocProcedural::CheckDisponibility(uint8 x, uint8 y, uint8 size)
{
	bool bDisponible = true;

	if (tMap[x].Ligne[y]==0)
	{
		if (size != 1)
		{
			for (int i = 1; i < size; i++)
			{
				if (tMap[x + i].Ligne[y] != 0)
				{
					bDisponible = false;
					break;
				}

				if (tMap[x].Ligne[y + i] != 0)
				{
					bDisponible = false;
					break;
				}

				if (tMap[x + i].Ligne[y + i] != 0)
				{
					bDisponible = false;
					break;
				}
			}
		}
	}

	return bDisponible;
}

void ABlocProcedural::PopulateMap(uint8 nDifficulty)
{
	int nbIteration = 0;
	while (nDifficulty>0 && nbIteration<100)
	{
		nbIteration++;

		
		uint8 x = FMath::RandRange(0, 9);
		uint8 y = FMath::RandRange(0, 9);
		uint8 size = FMath::RandRange(1, 3);

		TObstacleStructs obstacle;

		if (CheckDisponibility(x, y, size))
		{
			for (int i = 0; i < size; i++)
			{
				tMap[x + i].Ligne[y] = 1;
				tMap[x].Ligne[y + i] = 1;
				tMap[x + i].Ligne[y + i] = 1;
			}

			nDifficulty -= size;
			nbIteration--;
		}
	}
}

void ABlocProcedural::AddObstacle(uint8 difficulty, uint8 size, TSubclassOf<AActor> Obstacle)
{
	FObstacleStruct obstacle;
	obstacle.nDifficulty = difficulty;
	obstacle.nSize = size;
	obstacle.Obstacle = Obstacle;
	TObstacleStructs.Add(obstacle);
}

// Called every frame
void ABlocProcedural::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

