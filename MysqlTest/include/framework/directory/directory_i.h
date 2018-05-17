/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			directory.h
* 	@brief	:			
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan addע��ͷ
*/

#ifndef _DIRECTORY_I_H
#define _DIRECTORY_I_H

#include <data_types.h>

#include <string/string_i.h>
#include <os/os_directory_i.h>
#include <errno/error_i.h>
#include <trace/trace_i.h>
#include <memory_i.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>


class fileI;

class DLL_EXPORT directoryI
{
public:													//add Constructor by zhangxs at 2013-4-19
	directoryI();
	virtual ~directoryI();

public:
	/** 
	*
	* 	func name	:	getNext
	*	@brief		:	        
	*	@output		:	fileI **result����ȡ�����ļ�ָ��
	*	@param		:		    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int32 getNext(fileI **result);

	/** 
	*
	* 	func name	:	getNextEntry
	*	@brief		:	        
	*	@param		:		    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note		:	������һ���ļ�		
	*
	*/
	t_int32 getNextEntry();

	//�ر�Ŀ¼��
	t_int32 hasEntry(t_bool *result);
	

	t_int32 init(fileI *file);

	/** 
	* 	func name	:	init
	*	@brief		:	����stringI���Ͷ�Ŀ¼���г�ʼ��
	*	@input		:	dir��Ŀ¼·��
	*   @return		:	��ʼ���ɹ�����E_OK��ʧ�ܷ���E_FAIL;
	*	@author		:	zhang_xusheng
	*	@note:	    2013-04-16	
	*/
	t_int32 init(const t_int8 *dir);

	/** 
	* 	func name:	dirClose
	*	@brief:	    Ŀ¼�ر�
	*	@input:		void
	*   @return:	��ʼ���ɹ�����E_OK��ʧ�ܷ���E_FAIL;
	*	@author:	
	*	@note:	    2013-04-16	
	*/
	t_int32 dirClose();

	/** 
	*
	* 	func name:		getNextFile
	*	@brief:	        
	*	@param:		    fileI **result�����ҵ����ļ�ָ��
	*	@param:		    
	*	@return:		�ɹ���E_OK��ʧ�ܣ�0��E_NOMEM,��fail
	*	@author:	     
	*	@note:			��getNext()��������
	*
	*/
	t_int32 getNextFile(fileI **result);

public:

	/** 
	* 	func name	:	dirCreate
	*	@brief		:	����Ŀ¼
	*	@input		:	path--Ŀ¼·����
	*	@input		:	permission--Ŀ¼Ȩ��
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirCreate(const t_int8 *path ,t_int32 permission);

	/** 
	* 	func name	:	dirDelete
	*	@brief		:	ɾ��Ŀ¼
	*	@input		:	path--Ŀ¼·����
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirDelete(const t_int8 *path);

	/** 
	* 	func name	:	dirOpen
	*	@brief		:	Ŀ¼��
	*	@input		:	path--ԭĿ¼��
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	    2012-12-14		
	*/
	t_int32 dirOpen(const t_int8 *path);

	/** 
	* 	func name	:	fileCopy
	*	@brief		:	��Ŀ¼�µ�ĳ���ļ���������һ��Ŀ¼��
	*	@input		:	fPathName--�ļ�·����
	*	@input		:	tPathName--��������Ŀ¼·����
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 fileCopy(const t_int8 *fpathname, const t_int8 *tpathname);

	/** 
	* 	func name	:	dirCopy
	*	@brief		:	����Ŀ¼
	*	@input		:	fPathName--��������Ŀ¼·����
	*	@input		:	tPathName--��������Ŀ¼·����
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirCopy(const t_int8 *fpathname, const t_int8 *tPathName);

	/** 
	* 	func name	:	dirRename
	*	@brief		:	Ŀ¼������
	*	@input		:	oldName--ԭĿ¼��
	*	@input		:	newName--��Ŀ¼��
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirRename(const t_int8 *oldName, const t_int8 *newName);

	/** 
	* 	func name	:	dirRead
	*	@brief		:	Ŀ¼��ȡ
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirRead();


	t_int32 dirSeek(long int loc);
	t_int32 dirTell();

	/** 
	* 	func name	:	dirScan
	*	@brief		:	Ŀ¼ɨ��
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirScan(const char *path);

	t_int32 dirRewind();

	/** 
	* 	func name	:	isDir
	*	@brief		:	�ж��Ƿ���Ŀ¼
	*	@input		:	pathΪĿ¼·����
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_bool isDir(const char *path);

	/** 
	* 	func name	:	isFile
	*	@brief		:	�ж��Ƿ����ļ�
	*	@input		:	pathΪ�ļ�·����
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_bool isFile(const char *path);

	/** 
	* 	func name	:	isSpecialDir
	*	@brief		:	�ж��Ƿ����ر�Ŀ¼
	*	@input		:	pathΪĿ¼·����
	*   @return		:	����E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_bool isSpecialDir(const char *path);
public:
	/** 
	* 	func name	:	getmPath
	*	@brief		:	��ȡ��ǰ�ĸ�Ŀ¼·��
	*	@output		:	Path��string���͵�Ŀ¼
	*   @return		:	��ʼ���ɹ�����E_OK��ʧ�ܷ���E_FAIL;
	*	@author		:	zhang_xusheng
	*	@note		:	2013-04-17
	*/
	t_int32 getmPath(stringI &Path);
	
private:
	stringI mParentPath;	//��Ŀ¼·��


#ifdef WIN32

	WIN32_FIND_DATA findFileData;
	HANDLE hFile;
	t_int32 m_result;

#endif

};


#endif

