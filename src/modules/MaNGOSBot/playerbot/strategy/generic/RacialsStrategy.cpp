#include "botpch.h"
#include "../../playerbot.h"
#include "RacialsStrategy.h"

using namespace ai;


class RacialsStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	RacialsStrategyActionNodeFactory()
	{
		creators["berserking"] = &berserking;			//boost? or often?
		creators["blood fury"] = &blood_fury;			//boost? or often?
		creators["cannibalize"] = &cannibalize;			//loot
		creators["escape artist"] = &escape_artist;		//cc need trigger
		creators["shadowmeld"] = &shadowmeld;
		creators["stoneform"] = &stoneform;				//critical health triggered *TODO add trigger sap-ed*
		creators["war stomp"] = &war_stomp;				//cc need trigger
		creators["will of the forsaken"] = &will_of_the_forsaken;	//cc need trigger SPELL_AURA_MOD_FEAR  if (HasAuraType(SPELL_AURA_MOD_STUN) || HasAuraType(SPELL_AURA_MOD_ROOT))
		creators["mana tap"] = &mana_tap;				//ch
		creators["find treasure"] = &find_treasure;					//boost? or often?
		creators["perception"] = &perception;		//boost? or often?
		creators["arcane torrent"] = &arcane_torrent;					//ch
		creators["gift of the naaru"] = &gift_of_the_naaru;   //critical health triggered
	}
private:
	static ActionNode* berserking(PlayerbotAI* ai)
	{
		return new ActionNode("berserking",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* blood_fury(PlayerbotAI* ai)
	{
		return new ActionNode("blood fury",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* cannibalize(PlayerbotAI* ai)
	{
		return new ActionNode("cannibalize",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* escape_artist(PlayerbotAI* ai)
	{
		return new ActionNode("escape artist",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* shadowmeld(PlayerbotAI* ai)
	{
		return new ActionNode("shadowmeld",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* stoneform(PlayerbotAI* ai)
	{
		return new ActionNode("stoneform",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* war_stomp(PlayerbotAI* ai)
	{
		return new ActionNode("war stomp",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* mana_tap(PlayerbotAI* ai)
	{
		return new ActionNode("mana tap",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* find_treasure(PlayerbotAI* ai)
	{
		return new ActionNode("find treasure",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* perception(PlayerbotAI* ai)
	{
		return new ActionNode("perception",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* will_of_the_forsaken(PlayerbotAI* ai)
	{
		return new ActionNode("will of the forsaken",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* arcane_torrent(PlayerbotAI* ai)
	{
		return new ActionNode("arcane torrent",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* gift_of_the_naaru(PlayerbotAI* ai)
	{
		return new ActionNode("gift of the naaru",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
};

void RacialsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	//boosters
	triggers.push_back(new TriggerNode("boost", NextAction::array(0, new NextAction("berserking", ACTION_HIGH + 6), NULL)));
	triggers.push_back(new TriggerNode("boost", NextAction::array(0, new NextAction("blood fury", ACTION_HIGH + 6), NULL)));

	//cannibalize
	triggers.push_back(new TriggerNode("cannibalize", NextAction::array(0, new NextAction("cannibalize", ACTION_HIGH + 6), NULL)));


	// Rooted, (Use racial escape artist)
	triggers.push_back(new TriggerNode("rooted", NextAction::array(0, new NextAction("escape artist", ACTION_EMERGENCY + 8), NULL)));


	// Sheeped, feared, stunned....(Use racial will of the forsaken)  WoF"
	triggers.push_back(new TriggerNode("WoF", NextAction::array(0, NextAction("will of the forsaken", ACTION_HIGH + 8), NULL)));

	// shadowmeld
	triggers.push_back(new TriggerNode("panic", NextAction::array(0, NextAction("shadowmeld", ACTION_HIGH + 8), NULL)));

	// Critical Health (Use racials)
	triggers.push_back(new TriggerNode("critical health", NextAction::array(0, NextAction("gift of the naaru", ACTION_CRITICAL_HEAL), NULL)));
	triggers.push_back(new TriggerNode("critical health", NextAction::array(0, NextAction("stoneform", ACTION_CRITICAL_HEAL + 1), NULL)));

	// war stomping 
	triggers.push_back(new TriggerNode("war stomp on enemy", NextAction::array(0, new NextAction("war stomp", ACTION_HIGH + 8), NULL)));


	triggers.push_back(new TriggerNode(
		"fear ward on party",
		NextAction::array(0, new NextAction("fear ward on party", ACTION_NORMAL + 6), NULL)));

	triggers.push_back(new TriggerNode(
		"panic",
		NextAction::array(0, new NextAction("shadowmeld", ACTION_EMERGENCY + 6), NULL)));

	triggers.push_back(new TriggerNode(
		"enemy player is attacking",
		NextAction::array(0, new NextAction("shadowguard", ACTION_EMERGENCY + 6), NULL)));
}

RacialsStrategy::RacialsStrategy(PlayerbotAI* ai) : Strategy(ai)
{
	actionNodeFactories.Add(new RacialsStrategyActionNodeFactory());
}
