#pragma once
using namespace std;

#include "Packet.h"

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

class SetHealthPacket : public Packet, public enable_shared_from_this<SetHealthPacket>
{
public:
	float health;
	int food;
	float saturation;

	ETelemetryChallenges damageSource; // 4J Added

	SetHealthPacket();
	SetHealthPacket(float health, int food, float saturation, ETelemetryChallenges damageSource);

	virtual void read(DataInputStream *dis);
	virtual void write(DataOutputStream *dos);
	virtual void handle(PacketListener *listener);
	virtual int getEstimatedSize();
	virtual bool canBeInvalidated();
	virtual bool isInvalidatedBy(shared_ptr<Packet> packet);

public:
	static shared_ptr<Packet> create() { return shared_ptr<Packet>(new SetHealthPacket()); }
	virtual int getId() { return 8; }
};

