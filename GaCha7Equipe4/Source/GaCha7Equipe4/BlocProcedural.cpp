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
	bloc.Ligne.Init(0,nTailleBloc);
	tMap.Init(bloc,nTailleBloc);
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

void ABlocProcedural::InsertObstacle(uint8 nX, uint8 nY, int32 nIndexObstacle, uint8 nSize)
{
	tMap[nX].Ligne[nY] = nIndexObstacle;
	if (nSize != 1)
	{
		for (int i = 1; i < nSize; i++)
		{
			tMap[nX + i].Ligne[nY] = nIndexObstacle;
			tMap[nX].Ligne[nY + i] = nIndexObstacle;
			tMap[nX + i].Ligne[nY + i] = nIndexObstacle;
		}
	}
}


void ABlocProcedural::PopulateMap(uint8 nDifficulty, FString TypeObstacle)
{
	int nbIteration = 0;
	while (nDifficulty>0 && nbIteration<100)
	{
		nbIteration++;
		uint8 x = FMath::RandRange(0, nTailleBloc);
		uint8 y = FMath::RandRange(0, nTailleBloc);

		
		TArray<FObstacleStruct> tObstacle;
		for (int i = 0; i < TObstacleStructs.Num(); ++i)
		{
			if (true) //Faire la gestion du type d'obstacle.
			{
				tObstacle.Add(TObstacleStructs[i]);
			}
		}
		
		uint8 r = FMath::RandRange(0, tObstacle.Num());
		FObstacleStruct obstacle = TObstacleStructs[r];

		
		if (CheckDisponibility(x, y, obstacle.nSize))
		{
			int32 Index = 0;
			for (int i = 0; i < TObstacleStructs.Num(); ++i)
			{
				if (TObstacleStructs[i].Obstacle == obstacle.Obstacle)
				{
					Index = i;
					break;
				}
			}

			InsertObstacle(x,y,Index,obstacle.nSize);
			
			nDifficulty -= obstacle.nDifficulty;
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

