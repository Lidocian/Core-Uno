#include "botpch.h"
#include "../../playerbot.h"
#include "RogueMultipliers.h"
#include "SubtletyRogueStrategy.h"

using namespace ai;

class SubtletyRogueStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	SubtletyRogueStrategyActionNodeFactory()
    {
        creators["riposte"] = &riposte;
        creators["mutilate"] = &mutilate;
        creators["sinister strike"] = &sinister_strike;
        creators["kick"] = &kick;
        creators["kidney shot"] = &kidney_shot;
        creators["rupture"] = &rupture;
        creators["backstab"] = &backstab;
    }
private:
    static ActionNode* riposte(PlayerbotAI* ai)
    {
        return new ActionNode ("riposte",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("mutilate"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mutilate(PlayerbotAI* ai)
    {
        return new ActionNode ("mutilate",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("sinister strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* sinister_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("sinister strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* kick(PlayerbotAI* ai)
    {
        return new ActionNode ("kick",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("kidney shot"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* kidney_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("kidney shot",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* rupture(PlayerbotAI* ai)
    {
        return new ActionNode ("rupture",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("eviscerate"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* backstab(PlayerbotAI* ai)
    {
        return new ActionNode ("backstab",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("mutilate"), NULL),
            /*C*/ NULL);
    }
};

SubtletyRogueStrategy::SubtletyRogueStrategy(PlayerbotAI* ai) : MeleeCombatStrategy(ai)
{
    actionNodeFactories.Add(new SubtletyRogueStrategyActionNodeFactory());
}

NextAction** SubtletyRogueStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("riposte", ACTION_NORMAL), NULL);
}

void SubtletyRogueStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    MeleeCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("combo points available", NextAction::array(0, new NextAction("rupture", ACTION_HIGH + 2), NULL)));
	triggers.push_back(new TriggerNode("medium threat", NextAction::array(0, new NextAction("vanish", ACTION_HIGH), NULL)));
	triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("evasion", ACTION_EMERGENCY), new NextAction("feint", ACTION_EMERGENCY), NULL)));
	triggers.push_back(new TriggerNode("kick", NextAction::array(0, new NextAction("kick", ACTION_INTERRUPT + 2), NULL)));
	triggers.push_back(new TriggerNode("kick on enemy healer", NextAction::array(0, new NextAction("kick on enemy healer", ACTION_INTERRUPT + 1), NULL)));
    triggers.push_back(new TriggerNode("behind target", NextAction::array(0, new NextAction("backstab", ACTION_NORMAL), NULL)));
	//stealth
	triggers.push_back(new TriggerNode("stealth", NextAction::array(0, new NextAction("stealth", ACTION_HIGH), NULL)));
}
