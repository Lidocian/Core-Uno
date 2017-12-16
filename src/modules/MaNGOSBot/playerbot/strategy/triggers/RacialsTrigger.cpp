#include "botpch.h"
#include "RacialsTrigger.h"


bool ManaTapTrigger::IsActive()
{
	return AI_VALUE2(bool, "has mana", "current target");
}