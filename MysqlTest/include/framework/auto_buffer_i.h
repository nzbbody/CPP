

#ifndef _AUTO_BUFFER_I_H
#define _AUTO_BUFFER_I_H



#include <data_types.h>
#include <list_i.h>
#include <smart_ptr_i.h>

class DLL_EXPORT autoBufferI : public smartPtrI
{
	friend class smartPtrI;
public:
	autoBufferI();
	virtual ~autoBufferI();


public:
	static autoBufferI *createBuffer(t_int8 *buffer, t_int32 bufferLength, t_bool isBackup = TRUE);

	t_bool setBuffer(t_int8 *buffer, t_int32 bufferLength);
	t_bool copyBuffer(t_int8 *buffer, t_int32 bufferLength);
	t_int8 *getBuffer();
	t_int32 getBufferSize();

public:

	t_int32 _dataLength;
	t_int8 *_data;
};


typedef smartPtrImpl<autoBufferI> smartAutoBufferI;

struct autoBufferDataRow
{
	t_int32 packetId;
	smartAutoBufferI sab;
};

typedef queueI<autoBufferDataRow *> autoBufferDataQueue;






#endif


