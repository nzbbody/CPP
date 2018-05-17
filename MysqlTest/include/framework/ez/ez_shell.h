
#ifndef _EZ_SHELL_H
#define _EZ_SHELL_H


#include <data_types.h>





class ezShell
{
public:
	virtual ~ezShell() {};

public:
	virtual t_int32 start() = 0;
	virtual t_int32 stop() = 0;

public:
	virtual t_int32 output(t_int8 *buffer, t_int32 bufferLength) = 0;
	

	
};



#endif

