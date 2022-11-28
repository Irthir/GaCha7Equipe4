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
	bloc.Ligne.Init(-1,nTailleBloc);
	tMap.Init(bloc,nTailleBloc);

	for (int i = 0; i < tMap.Num(); ++i)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ligne TMAP, %d"),tMap[i].Ligne.Num());
	}
}

bool ABlocProcedural::CheckDisponibility(uint8 x, uint8 y, uint8 size)
{
	bool bDisponible = true;
	
	//UE_LOG(LogTemp, Warning, TEXT("X %d Y %d"),x,y);

	if (x<tMap.Num() && y<tMap[x].Ligne.Num() && tMap[x].Ligne[y] == -1)
	{
		if (size != 1)
		{
			for (int i = 1; i < size; i++)
			{
				if ((x+i)<nTailleBloc && (y+i)<nTailleBloc)
				{
					if (tMap[x + i].Ligne[y] != -1 || tMap[x].Ligne[y + i] != -1 || tMap[x + i].Ligne[y + i] != -1)
					{
						UE_LOG(LogTemp, Warning, TEXT("Objets superposés."));
						bDisponible = false;
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Dépassement par taille."));
					bDisponible = false;
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Position hors tableau."));
		bDisponible = false;
	}

	
	UE_LOG(LogTemp, Warning, TEXT("Bool %d"),bDisponible);

	return bDisponible;
}

void ABlocProcedural::InsertObstacle(uint8 nX, uint8 nY, int32 nIndexObstacle, uint8 nSize)
{
	tMap[nX].Ligne[nY] = nIndexObstacle;
	if (nSize != 1)
	{
		for (int i = 1; i < nSize; i++)
		{
			tMap[nX + i].Ligne[nY] = -2;
			tMap[nX].Ligne[nY + i] = -2;
			tMap[nX + i].Ligne[nY + i] = -2;
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Obstacle Inserted, %d %d"), nX, nY);
}


void ABlocProcedural::PopulateMap(int32 nDifficulty, FString TypeObstacle)
{
	UE_LOG(LogTemp, Warning, TEXT("Difficulte, %d"), nDifficulty);
	
	int nbIteration = 0;
	while (nDifficulty>0 && nbIteration<10000)
	{
		//FMath::RandInit(FDateTime::Now().GetTicks());
		nbIteration++;
		uint8 x = FMath::RandRange(0, nTailleBloc-1);
		uint8 y = FMath::RandRange(0, nTailleBloc-1);

		
		TArray<FObstacleStruct> tObstacle;
		for (int i = 0; i < TObstacleStructs.Num(); ++i)
		{
			for (int j = 0; j < TObstacleStructs[i].Categorie.Num(); ++j)
			{
				if (TObstacleStructs[i].Categorie[j] == Categorie)
				{
					tObstacle.Add(TObstacleStructs[i]);
				}
			}
		}
		
		FObstacleStruct obstacle;
		uint8 r = FMath::RandRange(0, tObstacle.Num()-1);
		if (tObstacle.Num()!=0)
		{
			obstacle = tObstacle[r];

			//UE_LOG(LogTemp, Warning, TEXT("Taille Obstacle, %d"), obstacle.nSize);
		
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
}

void ABlocProcedural::AddObstacle(uint8 difficulty, uint8 size, TSubclassOf<AActor> Obstacle, TArray<FString> tCategorie)
{
	FObstacleStruct obstacle;
	obstacle.nDifficulty = difficulty;
	obstacle.nSize = size;
	obstacle.Obstacle = Obstacle;
	obstacle.Categorie = tCategorie;
	TObstacleStructs.Add(obstacle);
}

// Called every frame
void ABlocProcedural::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

