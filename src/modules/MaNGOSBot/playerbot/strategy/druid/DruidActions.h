#pragma once

#include "../actions/GenericActions.h"
#include "DruidShapeshiftActions.h"
#include "DruidBearActions.h"
#include "DruidCatActions.h"

namespace ai
{    
    class CastFaerieFireAction : public CastSpellAction
    {
    public:
        CastFaerieFireAction(PlayerbotAI* ai) : CastSpellAction(ai, "faerie fire") {}
    };
    class CastFaerieFireFeralAction : public CastSpellAction
    {
    public:
        CastFaerieFireFeralAction(PlayerbotAI* ai) : CastSpellAction(ai, "faerie fire (feral)") {}
    };
    class CastWrathAction : public CastSpellAction
    {
    public:
        CastWrathAction(PlayerbotAI* ai) : CastSpellAction(ai, "wrath") {}
    };
    class CastHurricaneAction : public CastSpellAction
    {
    public:
        CastHurricaneAction(PlayerbotAI* ai) : CastSpellAction(ai, "hurricane") {}
    };
    class CastMoonfireAction : public CastDebuffSpellAction
    {
    public:
        CastMoonfireAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "moonfire") {}
    };
    class CastInsectSwarmAction : public CastDebuffSpellAction
    {
    public:
        CastInsectSwarmAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "insect swarm") {}
    };
    class CastStarfireAction : public CastSpellAction
    {
    public:
        CastStarfireAction(PlayerbotAI* ai) : CastSpellAction(ai, "starfire") {}
    };
    class CastEntanglingRootsAction : public CastSpellAction
    {
    public:
        CastEntanglingRootsAction(PlayerbotAI* ai) : CastSpellAction(ai, "entangling roots") {}
    };
    class CastEntanglingRootsCcAction : public CastSpellAction
    {
    public:
        CastEntanglingRootsCcAction(PlayerbotAI* ai) : CastSpellAction(ai, "entangling roots on cc") {}
        virtual Value<Unit*>* GetTargetValue();
        virtual bool Execute(Event event);
    };
    class CastHibernateAction : public CastSpellAction
    {
    public:
        CastHibernateAction(PlayerbotAI* ai) : CastSpellAction(ai, "hibernate") {}
    };
///HEALS & BUFFS
    // Target: Self 
    class CastRejuvenationAction : public CastHealingSpellAction {
    public:
        CastRejuvenationAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "rejuvenation") {}
    };
    // Target: Self 
    class CastRegrowthAction : public CastHealingSpellAction {
    public:
        CastRegrowthAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "regrowth") {}
    };
    // Target: Self 
    class CastLifeBloomAction : public CastHealingSpellAction {
    public:
        CastLifeBloomAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lifebloom") {}
    };
    // Target: Self 
    // Healing: Swiftmend (Talent Cooldown)
    class CastSwiftmendAction : public CastHealingSpellAction {
    public:
        CastSwiftmendAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "swiftmend") {}
    };
    class CastHealingTouchAction : public CastHealingSpellAction {
    public:
        CastHealingTouchAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "healing touch") {}
    };
    // Target: Self 
    class CastMarkOfTheWildAction : public CastBuffSpellAction {
    public:
        CastMarkOfTheWildAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "mark of the wild") {}
    };
    // Target: Self 
    class CastThornsAction : public CastBuffSpellAction {
    public:
        CastThornsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "thorns") {}
    };
    // Target: Self 
    class CastAbolishPoisonAction : public CastCureSpellAction
    {
    public:
        CastAbolishPoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "abolish poison") {}
        virtual NextAction** getAlternatives();
    };
    // Target: Self 
    class CastNaturesGraspAction : public CastBuffSpellAction
    {
    public:
        CastNaturesGraspAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's grasp") {}
    };
    // Target: Self 
    class CastCurePoisonAction : public CastCureSpellAction
    {
    public:
        CastCurePoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cure poison") {}
    };
    // Target: Self 
    class CastInnervateAction : public CastSpellAction
    {
    public:
        CastInnervateAction(PlayerbotAI* ai) : CastSpellAction(ai, "innervate") {}
        virtual string GetTargetName() { return "self target"; }
    };
    // Target: Self 
    class CastBarkskinAction : public CastBuffSpellAction
    {
    public:
        CastBarkskinAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "barkskin") {}
    };
    // Target: Self 
    class CastTranquilityAction : public CastAoeHealSpellAction
    {
    public:
        CastTranquilityAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "tranquility") {}
    };
    // Target: Party
    class CastRejuvenationOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRejuvenationOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "rejuvenation") {}
    };
    // Target: Party
    class CastRegrowthOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRegrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "regrowth") {}
    };
    // Target: Party
    class CastLifeBloomOnPartyAction : public HealPartyMemberAction {
    public:
        CastLifeBloomOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lifebloom") {}
    };
    // Target: Party
    // Healing: Swiftmend (Talent Cooldown)
    class CastSwiftmendOnPartyAction : public HealPartyMemberAction {
    public:
        CastSwiftmendOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "swiftmend") {}
    };
    // Target: Party
    class CastHealingTouchOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHealingTouchOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "healing touch") {}
    };
    // Target: Party
    class CastRebirthAction : public ResurrectPartyMemberAction
    {
    public:
        CastRebirthAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "rebirth") {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge(NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
        }
    };
    // Target: Party
    class CastMarkOfTheWildOnPartyAction : public BuffOnPartyAction {
    public:
        CastMarkOfTheWildOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "mark of the wild") {}
    };
    // TODO buff on tank
    /*
    class CastThornsOnPartyActionAction : public BuffOnPartyAction {
    public:
        CastThornsOnPartyActionAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "thorns") {}
        virtual string GetTargetName() { return "tank"; }
    };*/
    // Target: Party
    class CastCurePoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCurePoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cure poison", DISPEL_POISON) {}
    };
    // Target: Party
    class CastAbolishPoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastAbolishPoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "abolish poison", DISPEL_POISON) {}
        virtual NextAction** getAlternatives();
    };
}
