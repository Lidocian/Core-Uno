#include "botpch.h"
#include "../../playerbot.h"
#include "RacialsStrategy.h"

using namespace ai;


class RacialsStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	RacialsStrategyActionNodeFactory()
	{
		creators["berserking"] = &berserking;			
		creators["blood fury"] = &blood_fury;			
		creators["cannibalize"] = &cannibalize;			
		creators["escape artist"] = &escape_artist;		  
		creators["shadowmeld"] = &shadowmeld;           
		creators["stoneform"] = &stoneform;				
		creators["war stomp"] = &war_stomp;				
		creators["will of the forsaken"] = &will_of_the_forsaken;	
		creators["mana tap"] = &mana_tap;				
		//creators["find treasure"] = &find_treasure;				
		creators["perception"] = &perception;		
		creators["arcane torrent"] = &arcane_torrent;					
		creators["gift of the naaru"] = &gift_of_the_naaru;   
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
//	static ActionNode* find_treasure(PlayerbotAI* ai)
//	{
//		return new ActionNode("find treasure",
//			/*P*/ NULL,
//			/*A*/ NULL,
//			/*C*/ NULL);
//	}
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
	///Boosters
	// Berserking
	triggers.push_back(new TriggerNode("berserking", NextAction::array(0, new NextAction("berserking", ACTION_HIGH + 6), NULL)));

	// Blood fury
	triggers.push_back(new TriggerNode("blood fury", NextAction::array(0, new NextAction("blood fury", ACTION_HIGH + 6), NULL)));

	///CC breakers 
	// Rooted, (Use racial escape artist)
	triggers.push_back(new TriggerNode("rooted", NextAction::array(0, new NextAction("escape artist", ACTION_EMERGENCY + 8), NULL)));

	// Sheeped, feared, stunned..(Use racial will of the forsaken)  WOtF"
	triggers.push_back(new TriggerNode("WOtF", NextAction::array(0, NextAction("will of the forsaken", ACTION_HIGH + 8), NULL)));

	// shadowmeld
	triggers.push_back(new TriggerNode("panic", NextAction::array(0, NextAction("shadowmeld", ACTION_HIGH + 8), NULL)));

	///Critical Health 
    // Gift of the naaru
	triggers.push_back(new TriggerNode("critical health", NextAction::array(0, NextAction("gift of the naaru", ACTION_CRITICAL_HEAL), NULL)));

	//Stoneform
	triggers.push_back(new TriggerNode("critical health", NextAction::array(0, NextAction("stoneform", ACTION_CRITICAL_HEAL + 1), NULL)));

	// Cannibalize
	triggers.push_back(new TriggerNode("cannibalize", NextAction::array(0, new NextAction("cannibalize", ACTION_HIGH + 6), NULL)));

	///Interrupts
	// War stomp
	triggers.push_back(new TriggerNode("war stomp", NextAction::array(0, new NextAction("war stomp", ACTION_INTERRUPT + 6), NULL)));

	// Arcane torrent
	triggers.push_back(new TriggerNode("arcane torrent",NextAction::array(0, new NextAction("arcane torrent", ACTION_INTERRUPT + 6), NULL)));

	///Buffs
	// Find treasure 
//	triggers.push_back(new TriggerNode("often",NextAction::array(0, new NextAction("find treasure", ACTION_NORMAL + 1), NULL)));

    // Mana tap
	triggers.push_back(new TriggerNode("mana tap", NextAction::array(0, new NextAction("mana tap", ACTION_INTERRUPT + 6), NULL)));

	// Perception 
	triggers.push_back(new TriggerNode("perception", NextAction::array(0, new NextAction("perception", ACTION_HIGH + 8), NULL)));
}

RacialsStrategy::RacialsStrategy(PlayerbotAI* ai) : Strategy(ai)
{
	actionNodeFactories.Add(new RacialsStrategyActionNodeFactory());
}
