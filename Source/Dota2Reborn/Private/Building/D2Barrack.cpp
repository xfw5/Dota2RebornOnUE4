// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2Barrack.h"
#include "D2Creep.h"


// Sets default values
AD2Barrack::AD2Barrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SComp->Mobility = EComponentMobility::Static;
	RootComponent = SComp;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SComp);

	CreepsDirector = CreateDefaultSubobject<UD2CreepsDirector>(TEXT("Creeps Director"));
}

// Called when the game starts or when spawned
void AD2Barrack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD2Barrack::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AD2Barrack::SpawnCreeps()
{
	CreepsDirector->SpawnCreeps(Team, GetActorLocation(), GetActorRotation(), EnemyHome->GetActorLocation());
}
