/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			ez_cli.h
* 	@brief	:			命令处理函数
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan add注释头
*/

#ifndef _EZ_CLI_H
#define _EZ_CLI_H

#include <data_types.h>

#include <ez/ez_vector.h>

#include <ez/ez_shell.h>

/**
	注册命令信息列表
*/
struct ezCliElement
{
	const t_int8	*str;
	const t_int8	*help;

	t_int32 (*ezFunc)(t_handler handleId, t_int32, t_int8 **, void *);

	void	*userPtr;

	t_uint32 module;

	t_uint16 flags;
};

/**
	命令行解析结果
*/
enum
{
	EZ_CLI_PARSE_SUCCESS,
	EZ_CLI_PARSE_INCOMPLETE,
	EZ_CLI_PARSE_EMPTY_LINE,
	EZ_CLI_PARSE_AMBIGUOUS,
	EZ_CLI_PARSE_NO_MATCH,
	EZ_CLI_PARSE_NO_MODE,
	EZ_CLI_PARSE_ARGV_TOO_LONG,		
};

/**
	命令匹配结果	
*/
enum match_type
{
		none_match,
    	incomplete_match,
    	line_match,
    	partial_match,
    	exact_match,
};

/**
	命令叶节点
*/
struct ezCliNode
{

	struct ezCliElement *cliEl;

	ezVector *keywords;

	t_uint8 privilege;

	void *parent;
};

/**
	命令行模式信息
*/
struct ezCliMode
{
	t_int8 name[64];	//命令
	t_int8 prompt[64];	//提示符
};

/**
	命令目录树
*/
struct ezCliTree
{
	t_int32 mode;	

	t_uint8 privilege;

	ezVector *modes;

	ezVector *modeList;

	
	
};

typedef t_int32 (*ezCliOutFunc)(void *, const t_int8 *, ...); 

#define EZ_CLI_ARGC_MAX 15


struct ezCli
{
	ezShell *shell;
	
	struct ezCliElement *cliElement;
	struct ezCliTree *cliTree;

	t_int32 argc;
	t_int8 *argv[EZ_CLI_ARGC_MAX];

	t_int8  prompt[64];
	
	t_uint32 mode;

	struct ezCliNode *execNode;

	ezCliOutFunc outFunc;
	void *outVal;


};


/** 
*
* 	func name	:	ezCliNew
*	@brief		:	创建命令行	 
*	@param		:		    
*	@return		:	struct ezCli指针
*	@author		:	     
*	@note		:	申请一片动态空间，并返回struct ezCli指针
*
*/
struct ezCli *ezCliNew(void);


/** 
*
* 	func name	:	ezCliNew
*	@brief		:	释放命令行	 
*	@param		:	要释放的struct ezCli类型的对象	    
*	@return		:	void
*	@author		:	     
*	@note		：	与ezCliNew()成对调用
*
*/
void ezCliFree(struct ezCli *cli);

/** 
*
* 	func name	:	ezCliTreeNew
*	@brief		:	创建命令目录树	 
*	@output		:	struct ezCli类型的指针	    
*	@return		:	void
*	@author		:	     
*	@note		：	
*
*/
struct ezCliTree *ezCliTreeNew(void);

/** 
*
* 	func name	:	ezCliTreeFree
*	@brief		:	释放命令目录树	 
*	@param		:	要释放的struct ezCliTree类型的对象	    
*	@return		:	void
*	@author		:	     
*	@note		：	与ezCliTreeNew()成对调用
*
*/
void ezCliTreeFree(struct ezCliTree *cliTree);

/** 
*
* 	func name	:	ezCliTreeInit
*	@brief		:	命令目录树初始化 
*	@input		:	待初始化的ezCliTree *cliTree	    
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliTreeInit(ezCliTree *cliTree);
t_int32 ezCliTreeExit(ezCliTree *cliTree);
/** 
*
* 	func name	:	ezCliGetMode
*	@brief		:	获取命令行模式 
*	@input		:	struct ezCliTree *cli：命令树
*	@input		:	name:命令
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliGetMode(struct ezCliTree *cli, const t_int8 *name);

/** 
*
* 	func name	:	ezCliRegisterMode
*	@brief		:	注册命令行模式
*	@input		:	struct ezCliTree *cli：命令树
*	@input		:	name:命令
*	@input		:	prompt:提示符
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliRegisterMode(struct ezCliTree *cli, const t_int8 *name, t_int8 *prompt);

/** 
*
* 	func name	:	ezCliRegisterCmd
*	@brief		:	注册命令行命令
*	@input		:	struct ezCliTree *cli：命令树
*	@input		:	name:命令
*	@input		:	flags: 标志位
*	@input		:	struct ezCliElement *cliEl:注册命令信息列表
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliRegisterCmd(struct ezCliTree *cli, const t_int8 *name, t_int16 flags, struct ezCliElement *cliEl);

/** 
*
* 	func name	:	ezCliParse
*	@brief		:	命令行解析
*	@input		:	struct ezCli *cli：命令行
*	@input		:	name:命令
*	@return		:	0：失败； 其它返回值见“命令解析结果”
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliParse(struct ezCli *cli, t_int8 *name);

/** 
*
* 	func name	:	ezCliOut
*	@brief		:	命令行输出
*	@input		:	struct ezCli *cli：命令行
*	@input		:	format:变量
*	@return		:	
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliOut(struct ezCli *cli, const t_int8 *format, ...);

/** 
*
* 	func name	:	ezCliPrompt
*	@brief		:	命令行提示符
*	@input		:	struct ezCli *cli：命令行
*	@return		:	命令名
*	@author		:	     
*	@note		：	
*
*/
t_int8 *ezCliPrompt(struct ezCli *cli);

/** 
*
* 	func name	:	ezCliDescribe
*	@brief		:	命令行帮助信息
*	@input		:	struct ezCli *cli：命令行
*	@input		:	cp:cursion pointer
*	@return		:	
*	@author		:	     
*	@note		：	
*
*/
t_int32 ezCliDescribe(struct ezCli *cli, t_int8 *cp);

#endif

