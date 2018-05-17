

#ifndef _EZ_VTY_H
#define _EZ_VTY_H

#include <data_types.h>

#include <ez/ez_telnet.h>

#include <tvbuff.h>

#include <ez/ez_cli.h>



enum vtyType
{
	VTY_TERM,
	VTY_SHELL,
	VTY_SHELL_SERV
};

enum vtyMode
{
	VTY_LOGIN,
	VTY_AUTH,
	VTY_EXEC,
	VTY_CLOSE,
};

struct ezVty 
{
	enum vtyType type;	//远程连接类型

	enum vtyMode mode;	//vty当前模式
	
	struct ezCli *cli;	//

	t_int32 cliFd;		//命令行句柄

	struct prefix *local;
	struct prefix *remote;

	/* Failure count */
	t_int32 fail;
	t_int32 login_fail;

	t_int8 vtyBuf[4096];

	t_int8 vtyBufFeeds[4096];
	
	/* Output buffer. */
	struct tvbuff * tvb;

	/* Command input buffer */
	t_int8 *buf;

	/* Command cursor point */
	t_int32 cp;

	/* Command length */
	t_int32 length;

	/* Command max length. */
	t_int32 max;

	/* User name temp buff*/

	t_int8 userName[512];

	/* Histry of command */
#define VTY_MAXHIST 20
	t_int8 *hist[VTY_MAXHIST];

	/* History lookup current point */
	t_int32 hp;

	/* History insert end point */
	t_int32 hindex;

	/* For current referencing point of interface, route-map,
	access-list etc... */
	void *index;

	/* For multiple level index treatment such as key chain and key. */
	void *index_sub;

	void *index_sub_sub;

	/* For escape character. */
	t_int8 escape;

	/* IAC handling */
	t_int8 iac;

	/* IAC SB handling */
	t_int8 iac_sb_in_progress;


//	struct buffer * sb_buffer;

	/* Window width/height. */
	t_int32 width;
	t_int32 height;

	/* Configure lines. */
	t_int32 lines;

	/* Current executing function pointer. */
	t_int32 (*func) (struct ezVty *, void *arg);

	/* Terminal monitor. */
	t_int32 monitor;
#define VTY_MONITOR_CONFIG      (1 << 0)
#define VTY_MONITOR_OUTPUT      (1 << 1)

	/* In configure mode. */
	t_int32 config;

	/* Should the command be added to history. */
	t_int8 history;

	/* For vty buffer.  */
	t_int32 lp;
	t_int32 lineno;

};


struct ezVty *vtyNew(void);
void vtyFree(struct ezVty *vty);

t_int32 vtyHandleInput(struct ezVty *vty, t_int32 cliFd, t_uint8 *buf, t_int32 bufLen);

void vtyPrompt(struct ezVty *vty);
t_int32 vtyOut (struct ezVty *vty, const t_int8 *format, ...);
void vtyFlush (struct ezVty *vty);


void vtyEchoMode(struct ezVty *vty);

#endif
