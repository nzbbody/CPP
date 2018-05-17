
#ifndef _EZ_SHELL_TREE_H
#define _EZ_SHELL_TREE_H

#include <ez/ez_cli.h>
#include <singleton_i.h>

#define NODENAME_MAX_SIZE	64
#define CMDNAME_NAX_SIZE	64
#define	CMDHELP_MAX_SIZE	256
#define ROOT_NODE		"global"
/**
	shell ��������Դ
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
		ע��������
	*/
	t_int32 treeInit();
	/**
		ע��������
	*/
	t_int32 treeExit();
	/**
		����������ע������
	*/
	t_int32 regCmd(cliCmd &cmd);

	/**
		����������ע����
	*/
	t_int32 regNode(cliNode &node);

	struct ezCliTree * getShellTree(void);
private:
	struct ezCliTree *mCliTree;/// Ŀ¼��
};


typedef singletonI<ezShellTree> ezShellTreeSingleton;




DLL_EXPORT t_int32 shellCmdAdd(cliCmd &cmd);
/** 
*
* 	class name	:		shellNodeAdd
*	@brief		:	    �����н������
*						
*	@author		:	    zhang_xusheng 
*	@note:		:		����ӿڻ��ڴ����׶�
*
*/
DLL_EXPORT t_int32 shellNodeAdd(cliNode &Node);

DLL_EXPORT t_int32 shellPrintf(t_handler cli, t_int8 *fmt, ...);

#endif
