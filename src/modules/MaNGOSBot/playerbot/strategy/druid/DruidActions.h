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

	class CastProwlAction : public CastSpellAction {
	public:
		CastProwlAction(PlayerbotAI* ai) : CastSpellAction(ai, "prowl") {}
		virtual string GetTargetName() { return "self target"; }

	};

	// Target: Self 
	// Healing: Rejuvenation (HoT)
	//
	class CastRejuvenationAction : public CastHealingSpellAction {
	public:
		CastRejuvenationAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "rejuvenation") {}
	};

	// Target: Self 
	// Healing: Regrowth (HoT)
	//
	class CastRegrowthAction : public CastHealingSpellAction {
	public:
		CastRegrowthAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "regrowth") {}
	};

	// Target: Self 
	// Healing: Life Bloom (HoT)
	//
	class CastLifeBloomAction : public CastHealingSpellAction {
	public:
		CastLifeBloomAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "life bloom") {}
	};

	// Target: Self 
	// Healing: Wild Growth (AoE HoT)
	//
	class CastWildGrowthAction : public CastHealingSpellAction {
	public:
		CastWildGrowthAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "wild growth") {}
	};

	// Target: Self 
	// Healing: Nourish (Short cast heal after HoTs applied)
	//
	class CastNourishAction : public CastHealingSpellAction {
	public:
		CastNourishAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "nourish") {}
	};

	// Target: Self 
	// Healing: Swiftmend (Talent Cooldown)
	//
	class CastSwiftmendAction : public CastHealingSpellAction {
	public:
		CastSwiftmendAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "swiftmend") {}
	};

	// Target: Self
	// Healing: Healing Touch (Long cast)
	//
	class CastHealingTouchAction : public CastHealingSpellAction {
	public:
		CastHealingTouchAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "healing touch") {}
	};

	// Target: Party
	// Healing: Rejuvenation (HoT)
	//
	class CastRejuvenationOnPartyAction : public HealPartyMemberAction
	{
	public:
		CastRejuvenationOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "rejuvenation") {}
	};

	// Target: Party
	// Healing: Regrowth (HoT)
	//
	class CastRegrowthOnPartyAction : public HealPartyMemberAction
	{
	public:
		CastRegrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "regrowth") {}
	};

	// Target: Party
	// Healing: Life Bloom (HoT)
	//
	class CastLifeBloomOnPartyAction : public HealPartyMemberAction {
	public:
		CastLifeBloomOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "life bloom") {}
	};

	//
	// Healing: Wild Growth (Talent Cooldown: AoE Heal)
	//
	class CastWildGrowthOnPartyAction : public HealPartyMemberAction
	{
	public:
		CastWildGrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "wild growth") {}
	};

	// Target: Party
	// Healing: Nourish (Short cast after HoTs applied)
	//
	class CastNourishOnPartyAction : public HealPartyMemberAction {
	public:
		CastNourishOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "nourish") {}
	};

	// Target: Party
	// Healing: Swiftmend (Talent Cooldown)
	//
	class CastSwiftmendOnPartyAction : public HealPartyMemberAction {
	public:
		CastSwiftmendOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "swiftmend") {}
	};

	// Target: Party
	// Healing: Healing Touch (Large Cast)
	//
	class CastHealingTouchOnPartyAction : public HealPartyMemberAction
	{
	public:
		CastHealingTouchOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "healing touch") {}
	};

	class CastReviveAction : public ResurrectPartyMemberAction
	{
	public:
		CastReviveAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "revive") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge(NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
		}
	};

	class CastRebirthAction : public ResurrectPartyMemberAction
	{
	public:
		CastRebirthAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "rebirth") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge(NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
		}
	};

	class CastMarkOfTheWildAction : public CastBuffSpellAction {
	public:
		CastMarkOfTheWildAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "mark of the wild") {}
	};

	class CastMarkOfTheWildOnPartyAction : public BuffOnPartyAction {
	public:
		CastMarkOfTheWildOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "mark of the wild") {}
	};

	class CastSurvivalInstinctsAction : public CastBuffSpellAction {
	public:
		CastSurvivalInstinctsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "survival instincts") {}
	};

	class CastThornsAction : public CastBuffSpellAction {
	public:
		CastThornsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "thorns") {}
	};

	class CastWrathAction : public CastSpellAction
	{
	public:
		CastWrathAction(PlayerbotAI* ai) : CastSpellAction(ai, "wrath") {}
	};

	class CastStarfallAction : public CastSpellAction
	{
	public:
		CastStarfallAction(PlayerbotAI* ai) : CastSpellAction(ai, "starfall") {}
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

	class CastNaturesGraspAction : public CastBuffSpellAction
	{
	public:
		CastNaturesGraspAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's grasp") {}
	};

	class CastHibernateAction : public CastSpellAction
	{
	public:
		CastHibernateAction(PlayerbotAI* ai) : CastSpellAction(ai, "hibernate") {}
	};

	class CastCurePoisonAction : public CastCureSpellAction
	{
	public:
		CastCurePoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cure poison") {}
	};

	class CastCurePoisonOnPartyAction : public CurePartyMemberAction
	{
	public:
		CastCurePoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cure poison", DISPEL_POISON) {}
	};

	class CastAbolishPoisonAction : public CastCureSpellAction
	{
	public:
		CastAbolishPoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "abolish poison") {}
		virtual NextAction** getAlternatives();
	};

	class CastAbolishPoisonOnPartyAction : public CurePartyMemberAction
	{
	public:
		CastAbolishPoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "abolish poison", DISPEL_POISON) {}

		virtual NextAction** getAlternatives();
	};

	class CastFrenziedRegenerationAction : public CastBuffSpellAction
	{
	public:
		CastFrenziedRegenerationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "frenzied regeneration") {}
	};

	class CastBarkskinAction : public CastBuffSpellAction
	{
	public:
		CastBarkskinAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "barkskin") {}
	};

	class CastInnervateAction : public CastSpellAction
	{
	public:
		CastInnervateAction(PlayerbotAI* ai) : CastSpellAction(ai, "innervate") {}

		virtual string GetTargetName() { return "self target"; }
	};

	class CastTranquilityAction : public CastAoeHealSpellAction
	{
	public:
		CastTranquilityAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "tranquility") {}
	};
}