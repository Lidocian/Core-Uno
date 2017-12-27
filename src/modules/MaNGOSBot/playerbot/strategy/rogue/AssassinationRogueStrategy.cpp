#include "botpch.h"
#include "../../playerbot.h"
#include "RogueMultipliers.h"
#include "AssassinationRogueStrategy.h"

using namespace ai;

class AssassinationRogueStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	AssassinationRogueStrategyActionNodeFactory()
	{
		creators["mutilate"] = &mutilate;
		creators["envenom"] = &envenom;
		creators["cheap shot"] = &cheap_shot;
		creators["kick"] = &kick;
		creators["kidney shot"] = &kidney_shot;
		creators["melee"] = &melee;
	}
private:
	static ActionNode* melee(PlayerbotAI* ai)
	{
		return new ActionNode("melee",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* mutilate(PlayerbotAI* ai)
	{
		return new ActionNode("mutilate",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("melee"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* envenom(PlayerbotAI* ai)
	{
		return new ActionNode("envenom",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("eviscerate"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* cheap_shot(PlayerbotAI* ai)
	{
		return new ActionNode("cheap shot",
			/*P*/ NextAction::array(0, new NextAction("stealth"), NULL),
			/*A*/ NULL,
			/*C*/ NextAction::array(0, new NextAction("melee"), NULL));
	}
	static ActionNode* kick(PlayerbotAI* ai)
	{
		return new ActionNode("kick",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("blind"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* kidney_shot(PlayerbotAI* ai)
	{
		return new ActionNode("kidney shot",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}

};

AssassinationRogueStrategy::AssassinationRogueStrategy(PlayerbotAI* ai) : MeleeCombatStrategy(ai)
{
	actionNodeFactories.Add(new AssassinationRogueStrategyActionNodeFactory());
}

NextAction** AssassinationRogueStrategy::getDefaultActions()
{
	return NextAction::array(0, new NextAction("melee", ACTION_NORMAL), NULL);
}

void AssassinationRogueStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	MeleeCombatStrategy::InitTriggers(triggers);

	//openings
	triggers.push_back(new TriggerNode("cheap shot open", NextAction::array(0, new NextAction("cheap shot", ACTION_NORMAL + 7), NULL)));
	triggers.push_back(new TriggerNode("can open from behind", NextAction::array(0, new NextAction("garrote", ACTION_NORMAL + 7), NULL)));
	//main rotation
	triggers.push_back(new TriggerNode("slice and dice", NextAction::array(0, new NextAction("slice and dice", ACTION_HIGH), NULL)));
	triggers.push_back(new TriggerNode("combo points available", NextAction::array(0, new NextAction("envenom", ACTION_NORMAL + 9), NULL)));
	triggers.push_back(new TriggerNode("mutilate", NextAction::array(0, new NextAction("mutilate", ACTION_NORMAL + 8), NULL)));
	triggers.push_back(new TriggerNode("rupture", NextAction::array(0, new NextAction("rupture", ACTION_NORMAL + 7), NULL)));
	//threat
	triggers.push_back(new TriggerNode("medium threat", NextAction::array(0, new NextAction("feint", ACTION_HIGH), NULL)));
	triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("evasion", ACTION_EMERGENCY), NULL)));
	//interrupts
	triggers.push_back(new TriggerNode("kick", NextAction::array(0, new NextAction("kick", ACTION_INTERRUPT), NULL)));
	triggers.push_back(new TriggerNode("kick on enemy healer", NextAction::array(0, new NextAction("kick on enemy healer", ACTION_INTERRUPT), NULL)));
	triggers.push_back(new TriggerNode("blind on enemy healer", NextAction::array(0, new NextAction("blind on enemy healer", ACTION_INTERRUPT), NULL)));
	//position
	triggers.push_back(new TriggerNode("behind target", NextAction::array(0, new NextAction("backstab", ACTION_NORMAL), NULL)));
	//aoe
	triggers.push_back(new TriggerNode("light aoe", NextAction::array(0, new NextAction("blade flurry", ACTION_HIGH + 3), NULL)));
	//stealth
	triggers.push_back(new TriggerNode("stealth", NextAction::array(0, new NextAction("stealth", ACTION_HIGH), NULL)));

}
