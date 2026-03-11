#pragma once
using namespace std;

#include "Packet.h"

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

