/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			ez_cli.h
* 	@brief	:			�������
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan addע��ͷ
*/

#ifndef _EZ_CLI_H
#define _EZ_CLI_H

#include <data_types.h>

#include <ez/ez_vector.h>

#include <ez/ez_shell.h>

/**
	ע��������Ϣ�б�
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
	�����н������
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
	����ƥ����	
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
	����Ҷ�ڵ�
*/
struct ezCliNode
{

	struct ezCliElement *cliEl;

	ezVector *keywords;

	t_uint8 privilege;

	void *parent;
};

/**
	������ģʽ��Ϣ
*/
struct ezCliMode
{
	t_int8 name[64];	//����
	t_int8 prompt[64];	//��ʾ��
};

/**
	����Ŀ¼��
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
*	@brief		:	����������	 
*	@param		:		    
*	@return		:	struct ezCliָ��
*	@author		:	     
*	@note		:	����һƬ��̬�ռ䣬������struct ezCliָ��
*
*/
struct ezCli *ezCliNew(void);


/** 
*
* 	func name	:	ezCliNew
*	@brief		:	�ͷ�������	 
*	@param		:	Ҫ�ͷŵ�struct ezCli���͵Ķ���	    
*	@return		:	void
*	@author		:	     
*	@note		��	��ezCliNew()�ɶԵ���
*
*/
void ezCliFree(struct ezCli *cli);

/** 
*
* 	func name	:	ezCliTreeNew
*	@brief		:	��������Ŀ¼��	 
*	@output		:	struct ezCli���͵�ָ��	    
*	@return		:	void
*	@author		:	     
*	@note		��	
*
*/
struct ezCliTree *ezCliTreeNew(void);

/** 
*
* 	func name	:	ezCliTreeFree
*	@brief		:	�ͷ�����Ŀ¼��	 
*	@param		:	Ҫ�ͷŵ�struct ezCliTree���͵Ķ���	    
*	@return		:	void
*	@author		:	     
*	@note		��	��ezCliTreeNew()�ɶԵ���
*
*/
void ezCliTreeFree(struct ezCliTree *cliTree);

/** 
*
* 	func name	:	ezCliTreeInit
*	@brief		:	����Ŀ¼����ʼ�� 
*	@input		:	����ʼ����ezCliTree *cliTree	    
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliTreeInit(ezCliTree *cliTree);
t_int32 ezCliTreeExit(ezCliTree *cliTree);
/** 
*
* 	func name	:	ezCliGetMode
*	@brief		:	��ȡ������ģʽ 
*	@input		:	struct ezCliTree *cli��������
*	@input		:	name:����
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliGetMode(struct ezCliTree *cli, const t_int8 *name);

/** 
*
* 	func name	:	ezCliRegisterMode
*	@brief		:	ע��������ģʽ
*	@input		:	struct ezCliTree *cli��������
*	@input		:	name:����
*	@input		:	prompt:��ʾ��
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliRegisterMode(struct ezCliTree *cli, const t_int8 *name, t_int8 *prompt);

/** 
*
* 	func name	:	ezCliRegisterCmd
*	@brief		:	ע������������
*	@input		:	struct ezCliTree *cli��������
*	@input		:	name:����
*	@input		:	flags: ��־λ
*	@input		:	struct ezCliElement *cliEl:ע��������Ϣ�б�
*	@return		:	E_OK / E_FAIL
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliRegisterCmd(struct ezCliTree *cli, const t_int8 *name, t_int16 flags, struct ezCliElement *cliEl);

/** 
*
* 	func name	:	ezCliParse
*	@brief		:	�����н���
*	@input		:	struct ezCli *cli��������
*	@input		:	name:����
*	@return		:	0��ʧ�ܣ� ��������ֵ����������������
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliParse(struct ezCli *cli, t_int8 *name);

/** 
*
* 	func name	:	ezCliOut
*	@brief		:	���������
*	@input		:	struct ezCli *cli��������
*	@input		:	format:����
*	@return		:	
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliOut(struct ezCli *cli, const t_int8 *format, ...);

/** 
*
* 	func name	:	ezCliPrompt
*	@brief		:	��������ʾ��
*	@input		:	struct ezCli *cli��������
*	@return		:	������
*	@author		:	     
*	@note		��	
*
*/
t_int8 *ezCliPrompt(struct ezCli *cli);

/** 
*
* 	func name	:	ezCliDescribe
*	@brief		:	�����а�����Ϣ
*	@input		:	struct ezCli *cli��������
*	@input		:	cp:cursion pointer
*	@return		:	
*	@author		:	     
*	@note		��	
*
*/
t_int32 ezCliDescribe(struct ezCli *cli, t_int8 *cp);

#endif

