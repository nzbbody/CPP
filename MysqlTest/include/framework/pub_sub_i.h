

#ifndef _PUB_SUB_H
#define _PUB_SUB_H

#include <data_types.h>



#include <environment_base.h>

#include <event_i.h>

class publishI;
class subscribeI;

class pubSubI
{
public:
	pubSubI();
	virtual ~pubSubI();

public:
	t_int32 start(environmentBase &envBase);
	t_int32 subMessage(stringI &subMsg);



private:
	publishI *publisher;
	subscribeI *subscirber;
//	eventI *eventer;

	//redisContext *rContext;

	
	
};

#endif


