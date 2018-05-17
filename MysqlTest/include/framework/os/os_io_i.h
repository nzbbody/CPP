


#ifndef _OS_IO_I_H
#define _OS_IO_I_H

#include <data_types.h>
#include <errno/error_i.h>

#define OS_IO_ENABLE 1
#define OS_IO_DISABLE 0

namespace OS_IO 
{

t_int32 makeNonblock(iohandle_t handle, t_int32 cmd);

t_int32 read(iohandle_t handle, t_int8 *buff, t_int32 buffLen);

t_int32 write(iohandle_t handle, t_int8 *buff, t_int32 buffLen);

};


#endif

