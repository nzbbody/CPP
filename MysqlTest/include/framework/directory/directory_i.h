/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			directory.h
* 	@brief	:			
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan add注释头
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
	*	@output		:	fileI **result：获取到的文件指针
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
	*	@note		:	查找下一个文件		
	*
	*/
	t_int32 getNextEntry();

	//关闭目录？
	t_int32 hasEntry(t_bool *result);
	

	t_int32 init(fileI *file);

	/** 
	* 	func name	:	init
	*	@brief		:	采用stringI类型对目录进行初始化
	*	@input		:	dir：目录路径
	*   @return		:	初始化成功返回E_OK，失败返回E_FAIL;
	*	@author		:	zhang_xusheng
	*	@note:	    2013-04-16	
	*/
	t_int32 init(const t_int8 *dir);

	/** 
	* 	func name:	dirClose
	*	@brief:	    目录关闭
	*	@input:		void
	*   @return:	初始化成功返回E_OK，失败返回E_FAIL;
	*	@author:	
	*	@note:	    2013-04-16	
	*/
	t_int32 dirClose();

	/** 
	*
	* 	func name:		getNextFile
	*	@brief:	        
	*	@param:		    fileI **result：查找到的文件指针
	*	@param:		    
	*	@return:		成功：E_OK；失败：0，E_NOMEM,或fail
	*	@author:	     
	*	@note:			供getNext()函数调用
	*
	*/
	t_int32 getNextFile(fileI **result);

public:

	/** 
	* 	func name	:	dirCreate
	*	@brief		:	创建目录
	*	@input		:	path--目录路径名
	*	@input		:	permission--目录权限
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirCreate(const t_int8 *path ,t_int32 permission);

	/** 
	* 	func name	:	dirDelete
	*	@brief		:	删除目录
	*	@input		:	path--目录路径名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirDelete(const t_int8 *path);

	/** 
	* 	func name	:	dirOpen
	*	@brief		:	目录打开
	*	@input		:	path--原目录名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	    2012-12-14		
	*/
	t_int32 dirOpen(const t_int8 *path);

	/** 
	* 	func name	:	fileCopy
	*	@brief		:	将目录下的某个文件拷贝到另一个目录下
	*	@input		:	fPathName--文件路径名
	*	@input		:	tPathName--拷贝到的目录路径名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 fileCopy(const t_int8 *fpathname, const t_int8 *tpathname);

	/** 
	* 	func name	:	dirCopy
	*	@brief		:	拷贝目录
	*	@input		:	fPathName--被拷贝的目录路径名
	*	@input		:	tPathName--拷贝到的目录路径名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirCopy(const t_int8 *fpathname, const t_int8 *tPathName);

	/** 
	* 	func name	:	dirRename
	*	@brief		:	目录重命名
	*	@input		:	oldName--原目录名
	*	@input		:	newName--新目录名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirRename(const t_int8 *oldName, const t_int8 *newName);

	/** 
	* 	func name	:	dirRead
	*	@brief		:	目录读取
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirRead();


	t_int32 dirSeek(long int loc);
	t_int32 dirTell();

	/** 
	* 	func name	:	dirScan
	*	@brief		:	目录扫描
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_int32 dirScan(const char *path);

	t_int32 dirRewind();

	/** 
	* 	func name	:	isDir
	*	@brief		:	判断是否是目录
	*	@input		:	path为目录路径名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_bool isDir(const char *path);

	/** 
	* 	func name	:	isFile
	*	@brief		:	判断是否是文件
	*	@input		:	path为文件路径名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_bool isFile(const char *path);

	/** 
	* 	func name	:	isSpecialDir
	*	@brief		:	判断是否是特别目录
	*	@input		:	path为目录路径名
	*   @return		:	返回E_OK,E_FAIL
	*	@author		:	xu_xiangdong
	*	@note		:	2012-12-14		
	*/
	t_bool isSpecialDir(const char *path);
public:
	/** 
	* 	func name	:	getmPath
	*	@brief		:	获取当前的父目录路径
	*	@output		:	Path：string类型的目录
	*   @return		:	初始化成功返回E_OK，失败返回E_FAIL;
	*	@author		:	zhang_xusheng
	*	@note		:	2013-04-17
	*/
	t_int32 getmPath(stringI &Path);
	
private:
	stringI mParentPath;	//父目录路径


#ifdef WIN32

	WIN32_FIND_DATA findFileData;
	HANDLE hFile;
	t_int32 m_result;

#endif

};


#endif

