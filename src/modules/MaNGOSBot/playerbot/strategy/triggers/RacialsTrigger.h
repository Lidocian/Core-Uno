#include "botpch.h"
#include "../../playerbot.h"
#include "GenericTriggers.h"
#include "HealthTriggers.h"
#include "../../PlayerbotAIConfig.h"
#include "Spell.h"
#include "SpellMgr.h"

using namespace ai;

class BerserkingTrigger : public BoostTrigger
{
public:
	BerserkingTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "berserking") {}
};

class BloodFuryTrigger : public BoostTrigger
{
public:
	BloodFuryTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "blood fury") {}
};

class CannibalizeTrigger : public Trigger {
public:

	CannibalizeTrigger(PlayerbotAI* ai) : Trigger(ai, "cannibalize") {}
	virtual bool IsActive()
	{
		Unit* target = AI_VALUE(Unit*, "current target");
		return AI_VALUE2(bool, "dead", GetTargetName());
		return target && AI_VALUE2(float, "distance", "current target") <= sPlayerbotAIConfig.meleeDistance;
	}
	
};

class WoFTrigger : public Trigger {	// Sheeped, feared, stunned....(Use will of the forsaken)  "WoF"
public:
	WoFTrigger(PlayerbotAI* ai) : Trigger(ai, "WoF") {}
		virtual bool IsActive()
		{
			return bot->HasAuraType(SPELL_AURA_MOD_FEAR);
			return bot->HasAuraType(SPELL_AURA_MOD_STUN);
			return bot->HasAuraType(SPELL_AURA_MOD_CHARM);
			return bot->HasAuraType(SPELL_AURA_MOD_CONFUSE);
			return bot->IsPolymorphed;
		}
	};

class RootedTrigger : public Trigger {  //escape artist
public:
	RootedTrigger(PlayerbotAI* ai) : Trigger(ai, "rooted") {}
	virtual bool IsActive()
	{
		return bot->HasAuraType(SPELL_AURA_MOD_ROOT);
	}
};

class ManaTapTrigger : public InterruptEnemyHealerTrigger
{
public:
	ManaTapTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "mana tap") {}
	virtual Value<Unit*>* GetTargetValue();
	virtual string getName() { return spell + " on enemy healer"; }
};

class WarStompTrigger : public SpellTrigger   // war stomp
{
public:
	WarStompTrigger(PlayerbotAI* ai, string spell) : SpellTrigger(ai, spell) {}

	virtual Value<Unit*>* GetTargetValue();
	virtual string getName() { return spell + " on enemy"; }
};
///another trigger for stoneform to remove bleeding, poisons, curses but im not sure about this
/*
class BleedingTrigger : public Trigger{
public:
	BleedingTrigger(PlayerbotAI* ai) : Trigger(ai, "bleeding") {}
	virtual string GetTargetName() { return "self target";
	
		Unit::AuraList const& PeriodicDamage = bot->GetAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
		for (Unit::AuraList::const_iterator i = PeriodicDamage.begin(); i != PeriodicDamage.end(); ++i)
			if (*i)->GetSpellProto()->Mechanic == MECHANIC_BLEED
				return;
	}
};*/