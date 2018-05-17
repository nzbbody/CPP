
#ifndef _EZ_SHELL_TREE_H
#define _EZ_SHELL_TREE_H

#include <ez/ez_cli.h>
#include <singleton_i.h>

#define NODENAME_MAX_SIZE	64
#define CMDNAME_NAX_SIZE	64
#define	CMDHELP_MAX_SIZE	256
#define ROOT_NODE		"global"
/**
	shell 命令树资源
*/

typedef t_int32 (* ezShellfunc)(t_handler cli, t_int32 argc, t_int8 **argv, void *);
struct cliNode
{
	t_int8 nodeName[NODENAME_MAX_SIZE];
	t_int8 prompt[CMDHELP_MAX_SIZE];
};
struct cliCmd
{
	t_int8	nodeName[NODENAME_MAX_SIZE];

	t_int8	cmdName[CMDNAME_NAX_SIZE];

	t_int8	cmdhelp[CMDHELP_MAX_SIZE];

	ezShellfunc	cmdCallback;

	void	*userPtr;
};

class DLL_EXPORT ezShellTree
{
public:
	ezShellTree();
	virtual ~ezShellTree();

public:
	/**
		注册命令树
	*/
	t_int32 treeInit();
	/**
		注销命令树
	*/
	t_int32 treeExit();
	/**
		向命令树中注册命令
	*/
	t_int32 regCmd(cliCmd &cmd);

	/**
		向命令树中注册结点
	*/
	t_int32 regNode(cliNode &node);

	struct ezCliTree * getShellTree(void);
private:
	struct ezCliTree *mCliTree;/// 目录树
};


typedef singletonI<ezShellTree> ezShellTreeSingleton;




DLL_EXPORT t_int32 shellCmdAdd(cliCmd &cmd);
/** 
*
* 	class name	:		shellNodeAdd
*	@brief		:	    命令行结点的添加
*						
*	@author		:	    zhang_xusheng 
*	@note:		:		这个接口还在待定阶段
*
*/
DLL_EXPORT t_int32 shellNodeAdd(cliNode &Node);

DLL_EXPORT t_int32 shellPrintf(t_handler cli, t_int8 *fmt, ...);

#endif
