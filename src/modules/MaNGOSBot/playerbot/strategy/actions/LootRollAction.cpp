#include "botpch.h"
#include "../../playerbot.h"
#include "LootRollAction.h"


using namespace ai;

bool LootRollAction::Execute(Event event)
{
    Player *bot = QueryItemUsageAction::ai->GetBot();

    WorldPacket p(event.getPacket()); //WorldPacket packet for CMSG_LOOT_ROLL, (8+4+1)
    ObjectGuid lootedTarget;
    uint32 itemSlot;
    uint8  rollType;
    p.rpos(0); //reset packet pointer
    p >> lootedTarget; //guid of the item rolled
    p >> itemSlot; //loot index
    p >> rollType; //need,greed or pass on roll

    Group* group = bot->GetGroup();
    if(!group)
        return false;

    RollVote vote = ROLL_PASS;
    for (vector<Roll*>::iterator i = group->GetRolls().begin(); i != group->GetRolls().end(); ++i)
    {
        if ((*i)->isValid() && (*i)->lootedTargetGUID == lootedTarget && (*i)->itemSlot == itemSlot)
        {
            uint32 itemId = (*i)->itemid;
            ItemPrototype const *proto = sItemStorage.LookupEntry<ItemPrototype>(itemId);
            if (!proto)
                continue;

            if (IsLootAllowed(itemId, bot->GetPlayerbotAI()))
            {
                vote = ROLL_NEED;
                break;
            }
        }
    }

    switch (group->GetLootMethod())
    {
    case MASTER_LOOT:
    case FREE_FOR_ALL:
        group->CountRollVote(bot, lootedTarget, itemSlot, ROLL_PASS);
        break;
    default:
        group->CountRollVote(bot, lootedTarget, itemSlot, vote);
        break;
    }

    return true;
}
