

#ifndef _EZ_TTY_SHELL_H
#define _EZ_TTY_SHELL_H

#ifndef WIN32
#include <data_types.h>

#include <ez/ez_shell.h>

//#include <termios.h>


#include <ez/ez_vty.h>

#include <ez/ez_shell_tree.h>

#include <io_data/io_data_i.h>

#include <event_handler_i.h>

#include <os/os_io_i.h>

class ezTtyI : public ioDataI
{
public:
	ezTtyI();
	virtual ~ezTtyI();

	
public:
	t_int32 open();
	t_int32 close();
	t_int32 read(t_int8 *buff, t_int32 buffLen, t_int32 &nRead);
	t_int32 write(t_int8 *buff, t_int32 buffLen, t_int32 &nWrite);
public:
	t_int32 enableTtyRaw();
	t_int32 disableTtyRaw();

private:
	struct termios saveTermios;/// tty属性

	t_int32 ttyFd;

	ezVty *mVty;///关联的虚拟终端
	
};

/**
	ttyShell 实现类
*/
class ezTtyShell : virtual public ezShell, public eventHandlerI
{
public:
	ezTtyShell();
	virtual ~ezTtyShell();

public:
	/** 开始ttyShell 服务 */
	t_int32 start();
	/** 停止ttyShell 服务*/
	t_int32 stop();




public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);


	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);

public:
	

	t_int32 output(t_int8 *buffer, t_int32 bufferLength);

private:
	ezTtyI mTty;
	
	ezVty *mVty;///关联的虚拟终端

};

#endif /// endif WIN32

#endif

