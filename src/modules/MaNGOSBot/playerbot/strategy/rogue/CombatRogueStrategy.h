#pragma once

#include "../Strategy.h"
#include "../generic/MeleeCombatStrategy.h"

namespace ai
{
	class CombatRogueStrategy : public MeleeCombatStrategy
	{
	public:
		CombatRogueStrategy(PlayerbotAI* ai);

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "combat dps"; }
		virtual NextAction** getDefaultActions();
	};
}