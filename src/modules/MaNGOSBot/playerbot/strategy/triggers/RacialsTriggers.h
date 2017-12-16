#include "botpch.h"
#include "../../playerbot.h"
#include "GenericTriggers.h"
#include "HealthTriggers.h"
#include "../../PlayerbotAIConfig.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "Player.h"

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

class WOtFTrigger : public Trigger {	// Sheeped, feared, stunned....(Use will of the forsaken)  "WOtF"
public:
	WOtFTrigger(PlayerbotAI* ai) : Trigger(ai, "WOtF") {}
		virtual bool IsActive()
		{
			return bot->HasAuraType(SPELL_AURA_MOD_FEAR);
			return bot->HasAuraType(SPELL_AURA_MOD_STUN);
			return bot->HasAuraType(SPELL_AURA_MOD_CHARM);
			return bot->HasAuraType(SPELL_AURA_MOD_CONFUSE);
		}
	};
///can be used elswhere too
class RootedTrigger : public Trigger {  //escape artist
public:
	RootedTrigger(PlayerbotAI* ai) : Trigger(ai, "rooted") {}
	virtual bool IsActive()
	{
		return bot->HasAuraType(SPELL_AURA_MOD_ROOT);
	}
};

class ManaTapTrigger : public InterruptSpellTrigger {
public:
	ManaTapTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "mana tap") {}
	virtual bool IsActive()
	{
	Unit* target = AI_VALUE(Unit*, "current target");
	return target && AI_VALUE2(bool, "has mana", "current target");
	}
};

///another trigger for stoneform to remove bleeding, poisons, curses but im not sure about this

/*class BleedingTrigger : public Trigger{
public:
	BleedingTrigger(PlayerbotAI* ai) : Trigger(ai, "bleeding") {}
	
};*/

class ArcanetorrentTrigger : public InterruptSpellTrigger
{
public:
	ArcanetorrentTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "arcane torrent") {}
	virtual bool IsActive()
	{
			Unit* target = AI_VALUE(Unit*, "current target");
			return target && AI_VALUE2(float, "distance", "current target") <= sPlayerbotAIConfig.spellDistance;
	}
		
};
class WarStompTrigger : public InterruptSpellTrigger
{
public:
	WarStompTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "war stomp") {}
	virtual bool IsActive()
	{
		Unit* target = AI_VALUE(Unit*, "current target");
		return target && AI_VALUE2(float, "distance", "current target") <= sPlayerbotAIConfig.tooCloseDistance;
	}

};

class PerceptionTrigger : public BuffTrigger
{
public:
	PerceptionTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "perception") {}
	virtual bool IsActive()
	{
		Unit* target = AI_VALUE(Unit*, "current target");
		return (target->getClass()) == CLASS_ROGUE;
		return target && AI_VALUE2(float, "distance", "current target") <= sPlayerbotAIConfig.spellDistance;
		
	}

};