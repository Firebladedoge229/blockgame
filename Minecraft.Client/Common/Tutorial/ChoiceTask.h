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
