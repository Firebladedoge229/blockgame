#pragma once
using namespace std;

#include "TutorialTask.h"

#if defined(XBOX)
#include "Xbox/TelemetryEnum.h"
#elif defined(DURANGO)
#include "Durango/TelemetryEnum.h"
#elif defined(ORBIS)
#include "Orbis/TelemetryEnum.h"
#elif defined(PS3)
#include "PS3/TelemetryEnum.h"
#elif defined(PSVITA)
#include "PSVita/TelemetryEnum.h"
#elif defined(WINDOWS)
#include "Windows64/TelemetryEnum.h"
#else
#error "Platform not supported"
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
