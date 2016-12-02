// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "D2Creature.generated.h"

/*
* Local dummy creature in client only.
* The same creature in different client may have different behavior.
*/
UCLASS(Blueprintable, classGroup = "D2Actor")
class DOTA2REBORN_API AD2Creature : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AD2Creature();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
