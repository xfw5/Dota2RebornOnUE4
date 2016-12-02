// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2Hero.h"
#include "D2Ability.h"


// Sets default values
AD2Hero::AD2Hero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	ArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(ArmComponent);

	// Character back view
	ArmComponent->SetRelativeLocation(FVector(-0, 0, 50));
	ArmComponent->SetRelativeRotation(FRotator(0, -80, 0));

	// Dota2 style camera controls.
	ArmComponent->bInheritPitch = false;
	ArmComponent->bInheritRoll = false;
	ArmComponent->bInheritYaw = false;

	// Make character always face with moving dir.
	UCharacterMovementComponent* CharMovementComp = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (CharMovementComp)
	{
		CharMovementComp->bOrientRotationToMovement = true;
	}
}

// Called when the game starts or when spawned
void AD2Hero::BeginPlay()
{
	Super::BeginPlay();

	GetComponents(Abilities);
}

// Called every frame
void AD2Hero::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	UNavigationSystem::SimpleMoveToLocation(Controller, CommandLocation);
}

// Called to bind functionality to input
void AD2Hero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveTo", IE_Pressed, this, &AD2Hero::MoveToCommandLocation);
}

void AD2Hero::MoveToCommandLocation()
{
	const APlayerController* PlayerController = Cast<APlayerController>(this->Controller);
	if (PlayerController)
	{
		FHitResult HitRet;
		TArray<TEnumAsByte<EObjectTypeQuery>> QueryType;
		TEnumAsByte<EObjectTypeQuery> Ground = UEngineTypes::ConvertToObjectType(COLLISION_GROUND);
		QueryType.Add(Ground);
		if (PlayerController->GetHitResultUnderCursorForObjects(QueryType, true, HitRet))
		{
			CommandLocation = HitRet.Location;
		}
	}
}

void AD2Hero::AttackingCommand()
{
	const APlayerController* PlayerController = Cast<APlayerController>(this->Controller);
	if (PlayerController)
	{
		FHitResult HitRet;
		ETraceTypeQuery TraceType = UEngineTypes::ConvertToTraceType(COLLISION_ATTACK_COMMAND);
		if (PlayerController->GetHitResultUnderCursorByChannel(TraceType, true, HitRet))
		{
			DesireAttackingTarget = nullptr;
			ID2ActorInterface* D2Actor = Cast<ID2ActorInterface>(HitRet.GetActor());
			if (D2Actor)
			{
				DesireAttackingTarget.SetObject(HitRet.GetActor());
				DesireAttackingTarget.SetInterface(D2Actor);
			}
		}
	}
}

ETeamType AD2Hero::GetTeamNum() const
{
	return Team;
}

void AD2Hero::SetTeamNum(ETeamType NewTeam)
{
	Team = NewTeam;
}

int AD2Hero::GetHealth() const
{
	return HealthPoint;
}

int AD2Hero::GetMaxHealth() const
{
	return Attributes.HitPoint.GetValue();
}

TArray<UD2Ability*> AD2Hero::GetAbilities() const
{
	return Abilities;
}

UD2Ability* AD2Hero::GetAbility(uint32 AbilityGID) const
{
	UD2Ability* TargetAbility = nullptr;
	for (UD2Ability* Ability : Abilities)
	{
		if (Ability->GetGID() == AbilityGID)
		{
			TargetAbility = Ability;
			break;
		}
	}

	return TargetAbility;
}

int AD2Hero::GetSightDistance() const
{
	return Attributes.SightDistance;
}

int AD2Hero::GetAttackRange() const
{
	return Attributes.AttackRange.GetValue();
}

