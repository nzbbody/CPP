#ifndef QUERY_COUNT_I_H
#define QUERY_COUNT_I_H

#include <data_types.h>
#ifdef WIN32
#define performanceCount LARGE_INTEGER
#else
#define performanceCount struct timeval
#endif

class DLL_EXPORT performanceI
{
public:
	performanceI();
	virtual ~performanceI();

private:
	performanceCount m_timeStart;
	performanceCount m_timeEnd;
	performanceCount m_timefrequence;
};

#define FUNC_SPEND_TIME performanceI m_performance

#endif
