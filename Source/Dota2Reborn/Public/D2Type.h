// Copyright 2016 CTP Spider, All Rights Reserved.

#pragma once

#include "D2Type.generated.h"

UENUM(BlueprintType, meta = (Bitflags))
enum class EAbilityBehaviour :uint8
{
	AB_Point				UMETA(DisplayName = "Point"),
	AB_UnitTarget			UMETA(DisplayName = "Unit Target"),
	AB_NOTarget				UMETA(DisplayName = "No Target"),
};
ENUM_CLASS_FLAGS(EAbilityBehaviour)

UENUM(BlueprintType, meta = (Bitflags))
enum class EAbilityTargetType :uint8
{
	AT_Hero			UMETA(DisplayName = "Hero"),
	AT_Base			UMETA(DisplayName = "Base"),
	AT_Building		UMETA(DisplayName = "Building"),
	AT_Creep		UMETA(DisplayName = "Creep"),
};
ENUM_CLASS_FLAGS(EAbilityTargetType)

UENUM(BlueprintType)
enum class EAbilityTargetTeam :uint8
{
	ATT_Enemy		UMETA(DisplayName = "Enemy"),
	ATT_Friendly	UMETA(DisplayName = "Friendly"),
	ATT_Both		UMETA(DisplayName = "Both"),
	ATT_Custom		UMETA(DisplayName = "Custom"),
	ATT_None		UMETA(DisplayName = "None"),
};

UENUM(BlueprintType)
enum class EAbilityDamageType :uint8
{
	ADT_Magic		UMETA(DisplayName = "Magic"),
	ADT_Physics		UMETA(DisplayName = "Physics"),
	ATT_Pure		UMETA(DisplayName = "Pure"),
};

UENUM(BlueprintType)
enum class EAttackType : uint8
{
	Melee		UMETA(DisplayName = "Melee"),
	Range		UMETA(DisplayName = "Range"),
};

UENUM(BlueprintType)
enum class ETeamType : uint8
{
	None,
	Friendly,
	Enemy,
	Neutral
};

UENUM(BlueprintType)
enum class ECreepType: uint8
{
	Normal,
	Super,
	Mega,
};

USTRUCT()
struct FBonusAttr
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, category = "Bonus")
	float BonusFlat;

	UPROPERTY(EditDefaultsOnly, category = "Bonus")
	float BonusPercent;

	FORCEINLINE FBonusAttr FBonusAttr::operator +=(const FBonusAttr& Other)
	{
		return FBonusAttr(BonusFlat + Other.BonusFlat, BonusPercent + Other.BonusPercent);
	}

	FBonusAttr()
	{
		BonusFlat = 0;
		BonusPercent = 0;
	}

	FBonusAttr(float Flat, float Percent)
	{
		BonusFlat = Flat;
		BonusPercent = Percent;
	}
};

USTRUCT(BlueprintType)
struct FAttrFloatType
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	float BaseValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	float BonusValue;

	FORCEINLINE int GetValue() const { return BaseValue + BonusValue; }

	FAttrFloatType()
	{
		BaseValue = 0;
		BonusValue = 0;
	}
};

USTRUCT(BlueprintType)
struct FAttrIntType
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	int BaseValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	int BonusValue;

	FORCEINLINE int GetValue() const { return BaseValue + BonusValue; }

	FAttrIntType()
	{
		BaseValue = 0;
		BonusValue = 0;
	}
};

USTRUCT()
struct FAbilityAttr
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attr")
	FAttrFloatType CastPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attr")
	FAttrIntType CastRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attr")
	TArray<FAttrIntType> ManaCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attr")
	TArray<FAttrIntType> Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Attr", Meta = (Bitmask, BitmaskEnum = "EAbilityBehaviour"))
	int32 Behaviour;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Attr", Meta = (Bitmask, BitmaskEnum = "EAbilityTargetType"))
	int32 TargetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Attr")
	EAbilityDamageType DamageType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Attr")
	EAbilityTargetTeam TargetTeam;
};

USTRUCT()
struct FHeroAttr
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	int SightDistance;

	/** Max health point */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Heal")
	FAttrIntType HitPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Heal")
	FAttrIntType HealthRegen;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr: Attack")
	EAttackType AttackType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrIntType AttackDamageMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrIntType AttackDamageMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrFloatType AttackSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrIntType AttackRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Defence")
	FAttrIntType PhysicsArmor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Defence")
	FAttrIntType MagicResistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr: Animate")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr: Animate")
	UAnimMontage* DeathAnim;
};

USTRUCT(BlueprintType)
struct FCreatureAttr
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	int SightDistance;

	/** Max health point for this creature */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr")
	FAttrIntType HitPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Attr: Attack")
	EAttackType AttackType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrIntType AttackDamageMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrIntType AttackDamageMax;

	/** Attack speed in seconds */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrFloatType AttackSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Attack")
	FAttrIntType AttackRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Defence")
	FAttrIntType PhysicsArmor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attr: Defence")
	FAttrIntType MagicResistance;

	UPROPERTY(EditDefaultsOnly, category = "Attr: Animate")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditDefaultsOnly, category = "Attr: Animate")
	UAnimMontage* DeathAnim;
};

USTRUCT(BlueprintType)
struct FCreepBufferData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Bonus")
	FAttrIntType DamageBonus;

	UPROPERTY(EditDefaultsOnly, Category = "Bonus")
	FAttrIntType HealthPointBonus;

	/* Gold gain decrease by killer when this pawn killed. */
	UPROPERTY(EditDefaultsOnly, Category = "Decrease")
	FAttrIntType GoldDecrease;

	/* Gold gain decrease by killer when this pawn killed. */
	UPROPERTY(EditDefaultsOnly, Category = "Decrease")
	FAttrIntType ExperienceDecrease;
};