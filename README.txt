D2 Reborn on UE4
  The purpose of Dota2 reborn on Unreal Engine 4 project, is demonstrate how to create a MMORPG styles game with a flexible and extendable combat system. The models and materials extract from dota2 work tools with source2 engine (WIP).
  (Personal Dota2 Mod project: https://github.com/xfw5/wonderland)

D2ActorInterface:
	TeamNum
	HealthPoint
	....

Creep: D2ActorInterface, CreepController(AIController)
Creature: D2ActorInterface, CreatureController(AIController)
Hero: D2ActorInterface, PlayerController
Building: D2ActorInterface

  D2ActorInterface is the base class/interface of all D2 actors; it defines the common behavior and attributes, only provider an actor facade.

Mechanics:
1)Abilities: 
  All abilities implements as blueprint assets and with low level ability/Spell event support. Make each ability can be custom and extendable as it need. The low level ability mechanics only designed the ability cast flow, and raise the event at the flow point. Like cast begin, cast end, cast failed, channel begin, channel interrupted, spell start, attack launched, attack missing and so on.

2)Attributes: 
  Actor attributes that affected by modifiers, such as moving speed, base attack damage, health, mana, armor, magic resistance. All attributes consist of two part: base value and bonus value (Attack Damage: 86 + 30). And each attribute has a BOOL field with bIsAttrDirty that indicated whether the attributes was modified. The field bIsAttrDirty just like transform position dirty flag to avoid unnecessary extra calculation.
  When the Attributes being modified, will raise the attributes event, notify the listener it was changed. Like HUD refresh actor attributes info, movement component refresh moving speed.
  Atrributes is blueprint read only, can't modified directly. All attributes must modified by modifier.
  Most of the D2Actors attributes implementation as USTRUCT(Not UObject) with editDefaultsOnly flag. Attributes as struct, has great helpful when debug the attributes status at runtime.
  If implementation attributes as UObject, the editor detail property windows can't be display the inner details cause of unreal engine reflection system limited. (Unity inspector can do that!)

3)Modifier:
  Modifier is the core conception of combat system. The entire combat system designs base on modifiers, and modifier can affected all attributes. Like Spell, Aura, Effects. Raise event when modifiers applied or removed.

Work Flow
e.g:
  Hero: Seven 
  Ability: Storm Bolt
  
  OnSpellStart: TrackingProjectile + FireSound(StormBolt)
  OnProjectileHitUnit: FireSound(StormBoltImpact) + FireEffect(StormBoltProjectileExplosion) + ActOnTargets(Apply Damage + ApplyModifier)
  Modifiers: modifier_storm_bolt(MODIFIER_STATE_STUNNED) + ApplyStunEffect

Anybody interesting in this project, contact me: xfw5@163.com









