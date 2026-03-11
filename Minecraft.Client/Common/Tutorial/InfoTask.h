#pragma once
using namespace std;

#include "TutorialTask.h"

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

// Information messages
class InfoTask : public TutorialTask
{
private:
	unordered_map<int, bool> completedMappings;

	ETelemetryChallenges m_eTelemetryEvent;

	bool CompletionMaskIsValid();
public:
	InfoTask(Tutorial *tutorial, int descriptionId, int promptId = -1, bool requiresUserInput = false, int iMapping = 0, ETelemetryChallenges telemetryEvent = eTelemetryChallenges_Unknown);
	virtual bool isCompleted();
	virtual int getPromptId();
	virtual void setAsCurrentTask(bool active = true);
	virtual void handleUIInput(int iAction);

private:
	void sendTelemetry();

};
