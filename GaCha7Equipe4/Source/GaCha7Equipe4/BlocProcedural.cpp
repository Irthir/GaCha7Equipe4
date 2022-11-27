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
	
}

void ABlocProcedural::InitMap()
{
	//TODO: Init map
}

bool ABlocProcedural::CheckDisponibility(uint8 x, uint8 y, uint8 size)
{
	//TODO : Check if the bloc is available
}

void ABlocProcedural::PopulateMap(uint8 nDifficulty)
{
	//TODO : Populate the map
}

// Called every frame
void ABlocProcedural::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

