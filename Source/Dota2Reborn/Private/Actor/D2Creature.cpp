// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2Creature.h"


// Sets default values
AD2Creature::AD2Creature()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AD2Creature::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD2Creature::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

