#include "stdafx.h"
#include <iostream>
#include "InputOutputStream.h"
#include "PacketListener.h"
#include "SetHealthPacket.h"

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

SetHealthPacket::SetHealthPacket()
{
	this->health = 0.0f;
	this->food = 0;
	this->saturation = 0;

	this->damageSource = eTelemetryChallenges_Unknown;
}

SetHealthPacket::SetHealthPacket(float health, int food, float saturation, ETelemetryChallenges damageSource)
{
	this->health = health;
	this->food = food;
	this->saturation = saturation;
	// this.exhaustion = exhaustion; // 4J - Original comment

	this->damageSource = damageSource;
}

void SetHealthPacket::read(DataInputStream *dis) //throws IOException 
{
	health = dis->readFloat();
	food = dis->readShort();
	saturation = dis->readFloat();
	//        exhaustion = dis.readFloat();

	damageSource = (ETelemetryChallenges)dis->readByte();
}

void SetHealthPacket::write(DataOutputStream *dos) //throws IOException 
{
	dos->writeFloat(health);
	dos->writeShort(food);
	dos->writeFloat(saturation);
	//        dos.writeFloat(exhaustion);

	dos->writeByte(damageSource);
}

void SetHealthPacket::handle(PacketListener *listener) 
{
	listener->handleSetHealth(shared_from_this());
}

int SetHealthPacket::getEstimatedSize()
{
	return 11;
}

bool SetHealthPacket::canBeInvalidated()
{
	return true;
}

bool SetHealthPacket::isInvalidatedBy(shared_ptr<Packet> packet)
{
	return true;
}
