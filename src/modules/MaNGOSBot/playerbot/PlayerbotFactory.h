#pragma once

#include "strategy/actions/InventoryAction.h"

class Player;
class PlayerbotMgr;
class ChatHandler;

using namespace std;
using ai::InventoryAction;

class PlayerbotFactory : public InventoryAction
{
public:
	PlayerbotFactory(Player* bot, uint32 level, uint32 itemQuality = 0) : bot(bot), level(level), itemQuality(itemQuality), InventoryAction(bot->GetPlayerbotAI(), "factory") {
		switch (bot->getClass()) {
		case CLASS_WARRIOR:
		case CLASS_PALADIN:
			role = ROLE_TANK;
			break;
		case CLASS_DRUID:
		case CLASS_PRIEST:
		case CLASS_SHAMAN:
			role = ROLE_HEALER;
			break;
		default:
			role = ROLE_DPS;
		}
	}

    static ObjectGuid GetRandomBot();
    void CleanRandomize();
    void Randomize();
    void Refresh();

private:
    void Randomize(bool incremental);
    void Prepare();
    void InitSecondEquipmentSet();
    void InitEquipment(bool incremental);
    bool CanEquipItem(ItemPrototype const* proto, uint32 desiredQuality);
    bool CanEquipUnseenItem(uint8 slot, uint16 &dest, uint32 item);
    void InitSkills();
    void InitTradeSkills();
    void UpdateTradeSkills();
    void SetRandomSkill(uint16 id);
    void InitSpells();
    void ClearSpells();
    void InitAvailableSpells();
    void InitSpecialSpells();
    void InitTalents();
    void InitTalents(uint32 specNo);
    void InitQuests();
    void InitPet();
    void ClearInventory();
    void InitAmmo();
    void InitMounts();
    void InitPotions();
    void InitFood();
    bool CanEquipArmor(ItemPrototype const* proto);
    bool CanEquipWeapon(ItemPrototype const* proto);
    void EnchantItem(Item* item);
    void AddItemStats(uint32 mod, uint8 &sph, uint8 &spd, uint8 &apa, uint8 &aps, uint8 &apr, uint8 &tank);
    bool CheckItemStats(uint8 sph, uint8 spd, uint8 apa, uint8 aps, uint8 apr, uint8 tank);
    void CancelAuras();
    bool IsDesiredReplacement(Item* item);
    void InitBags();
    void InitInventory();
    void InitInventoryTrade();
    void InitInventoryEquip();
    void InitInventorySkill();
    Item* StoreItem(uint32 itemId, uint32 count);
    void InitGuild();
	//void InitQuestSpells();

private:
    Player* bot;
    uint32 level;
    uint32 itemQuality;
	uint8 role;

    static uint32 tradeSkills[];
    static list<uint32> classQuestIds;
};
