

#ifndef _EZ_SHELL_IMPL_H
#define _EZ_SHELL_IMPL__H


#include <ez/ez_tty_shell.h>
#include <ez/ez_net_shell.h>
#include <ez/ez_shell_tree.h>



/** shell 实现类  */
class ezShellI
{


public:
	t_int32 start();
	t_int32 start(t_int32 ezPort);
	t_int32 stop();
	ezShellTree *getShell();

public:
	ezShellI();
	virtual ~ezShellI();

	
private:
#ifndef WIN32
	ezTtyShell *mTtyShell;///tty shell
#endif
	ezAgentShell *mAgentShell; ///net shell

	ezShellTree *mShellTree;///shell命令树资源
};

#endif


