// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "D2ActorInterface.h"
#include "D2Type.h"
#include "D2Hero.generated.h"


UCLASS(Blueprintable, classGroup = "D2Actor")
class DOTA2REBORN_API AD2Hero : public ACharacter, public ID2ActorInterface
{
	GENERATED_BODY()

private:
	FVector CommandLocation;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	USpringArmComponent* ArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UCameraComponent* CameraComponent;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	TArray<UD2Ability*> Abilities;

	UPROPERTY(VisibleInstanceOnly, category = "Status")
	int HealthPoint;

	UPROPERTY(VisibleInstanceOnly, Category = "Status")
	ETeamType Team;

	UPROPERTY(VisibleInstanceOnly, Category = "Status")
	TScriptInterface<ID2ActorInterface> DesireAttackingTarget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attr")
	FHeroAttr Attributes;
public:
	// Sets default values for this character's properties
	AD2Hero();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Move to player command point.
	void MoveToCommandLocation();

	void AttackingCommand();

	virtual ETeamType GetTeamNum() const override;

	virtual void SetTeamNum(ETeamType NewTeam) override;

	virtual int GetHealth() const override;

	virtual int GetMaxHealth() const override;
	
	virtual TArray<UD2Ability*> GetAbilities() const override;

	virtual UD2Ability* GetAbility(uint32 AbilityGID) const override;

	virtual int GetSightDistance() const override;


	virtual int GetAttackRange() const override;

};
