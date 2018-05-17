#ifndef TRACE_H_
#define TRACE_H_
#include <stdio.h>
class Trace
{
public:
	Trace()
	{
		printf("Hello\n");
	}


	~Trace()
	{
		printf("Goodbye\n");

	}
};
#endif