


#ifndef _DATA_CENTER_I_H
#define _DATA_CENTER_I_H


#include <data_types.h>

#include <hiredis/hiredis.h>

typedef enum{
	dc_connection_tcp,
	dc_connection_unix,
		
}dc_connection_type;

struct dataCenterConfig
{
	t_int32 connNum;
	dc_connection_type connType;
	
};

class dataCenterConnection
{
public:
	t_int32 connect(void);

	t_int32 isConnected(void);


private:
	redisContext *rc;
	
	
};

class dataCenterI
{

public:
	t_int32 init(dataCenterConfig &dcConfig);
	t_int32 exit(void);
	t_int32 start(void);
	t_int32 stop(void);

	
public:
	dataCenterConfig config;
	
	dataCenterConnection *connections;
};

#endif

