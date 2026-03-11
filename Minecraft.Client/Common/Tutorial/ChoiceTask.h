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

// Information messages with a choice
class ChoiceTask : public TutorialTask
{
private:
	int m_iConfirmMapping, m_iCancelMapping;
	bool m_bConfirmMappingComplete, m_bCancelMappingComplete;
	eTutorial_CompletionAction m_cancelAction;

	ETelemetryChallenges m_eTelemetryEvent;

	bool CompletionMaskIsValid();
public:
	ChoiceTask(Tutorial *tutorial, int descriptionId, int promptId = -1, bool requiresUserInput = false, int iConfirmMapping = 0, int iCancelMapping = 0, eTutorial_CompletionAction cancelAction = e_Tutorial_Completion_None, ETelemetryChallenges telemetryEvent = eTelemetryChallenges_Unknown);
	virtual bool isCompleted();
	virtual eTutorial_CompletionAction getCompletionAction();
	virtual int getPromptId();
	virtual void setAsCurrentTask(bool active = true);
	virtual void handleUIInput(int iAction);

private:
	void sendTelemetry();
};
