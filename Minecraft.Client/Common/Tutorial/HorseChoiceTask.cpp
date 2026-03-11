#include "stdafx.h"

#include <string>

#include "Minecraft.h"
#include "Tutorial.h"

#include "..\Minecraft.World\EntityHorse.h"

#include "HorseChoiceTask.h"

#if defined(_XBOX)
#include "Xbox/TelemetryEnum.h"
#elif defined(_DURANGO)
#include "Durango/TelemetryEnum.h"
#elif defined(ORBIS)
#include "Orbis/TelemetryEnum.h"
#elif defined(_PSVITA) || defined(__PSVITA__)
#include "PSVita/TelemetryEnum.h"
#elif defined(_WINDOWS64)
#include "Windows64/TelemetryEnum.h"
#else
#include "PS3/TelemetryEnum.h"
#endif

HorseChoiceTask::HorseChoiceTask(Tutorial *tutorial, int iDescHorse, int iDescDonkey, int iDescMule, int iPromptId,
								 bool requiresUserInput, int iConfirmMapping, int iCancelMapping, 
								 eTutorial_CompletionAction cancelAction, ETelemetryChallenges telemetryEvent)

	: ChoiceTask(tutorial, -1, iPromptId, requiresUserInput, iConfirmMapping, iCancelMapping, cancelAction, telemetryEvent)
{
	m_eHorseType = -1;
	m_iDescMule = iDescMule;
	m_iDescDonkey = iDescDonkey;
	m_iDescHorse = iDescHorse;
}

int HorseChoiceTask::getDescriptionId()
{
	switch (m_eHorseType)
	{
	case EntityHorse::TYPE_HORSE:	return m_iDescHorse;
	case EntityHorse::TYPE_DONKEY:	return m_iDescDonkey;
	case EntityHorse::TYPE_MULE:	return m_iDescMule;
	default:						return -1;
	}
	return -1;
}

void HorseChoiceTask::onLookAtEntity(shared_ptr<Entity> entity)
{
	if ( (m_eHorseType < 0) && entity->instanceof(eTYPE_HORSE) )
	{
		shared_ptr<EntityHorse> horse = dynamic_pointer_cast<EntityHorse>(entity);
		if ( horse->isAdult() ) m_eHorseType = horse->getType();
	}
}
