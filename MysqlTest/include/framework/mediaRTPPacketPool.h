#ifndef _MEDIARTPPACKETPOOL_H
#define _MEDIARTPPACKETPOOL_H

#include <framework_i.h>

#define MEDIARTPPACKETPOOL_DEFAULT_SIZE	10000

class mediaRtpPacketI;
class mediaRtpPacketPool
{
public:
	mediaRtpPacketPool();
	virtual ~mediaRtpPacketPool();

public:
	mediaRtpPacketI* createPacket();

	t_int32 recycle(mediaRtpPacketI* packet);

	void setMaxPoolSize(size_t maxPoolSize);

protected:
	size_t	m_maxPoolSize;
	mutexI	m_mutex;
	std::deque<mediaRtpPacketI*>	m_pool;
};

typedef singletonI<mediaRtpPacketPool> mediaRtpPacletPoolSingleten;

#endif
