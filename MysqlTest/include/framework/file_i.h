/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			file_i.h
* 	@brief	:			提供文件相关操作接口函数
* 	@author	:           chenjiang
*	@note	:	
*	@modify	:           hehairan add注释头
*/

#ifndef _FILE_I_H
#define _FILE_I_H

#include <os/os_file_i.h>
#include <directory/directory_i.h>
class directoryI;


#define PATH_MAX_SIZE 512

/** 
*
* 	class name	:		fileI
*	@brief		:	    主要提供对文件操作的功能函数，如创建、打开、关闭、删除、截断、读写、跳转
*						文件路径设置与获取、文件大小函数等
*	@author		:	    chenjiang 
*	@note:			
*
*/
class DLL_EXPORT fileI
{
public:
	/** 
	*
	* 	func name	:		fileI
	*	@brief		:	    构造函数
	*	@param		:		
	*	@return		:		无
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	fileI();

	/** 
	*
	* 	func name	:		fileI
	*	@brief		:	    构造函数
	*	@param		:		stringI &path 文件路径
	*	@return		:		
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	fileI(const stringI &path);

	/** 
	*
	* 	func name	:		~fileI
	*	@brief		:	    析构函数
	*	@param		:		
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	virtual ~fileI();

public:

	/** 
	*
	* 	func name	:		createFile
	*	@brief		:	    文件操作类析构函数
	*	@param		:		t_int32 type，打开文件类型
	*	@param		:		t_int32 permissons，打开文件权限
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 createFile();

	/** 
	*
	* 	func name	:		openFile
	*	@brief		:	    打开文件
	*	@param		:	    const t_int8* mode,打开文件的方式，比如说"r" "r+" "rw"
	*	@return		:	 	E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 openFile( const t_int8* mode );

	/** 
	*
	* 	func name	:		closeFile
	*	@brief		:	        关闭文件
	*	@param		:		    
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 closeFile();

	/** 
	*
	* 	func name	:		removeFile
	*	@brief		:	    删除文件
	*	@param		:		    
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:			
	*
	*/
	t_int32 removeFile();

	/** 
	*
	* 	func name	:		truncFile
	*	@brief		:	    截断文件
	*	@param		:		t_int64 &length
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 truncFile(t_int32 &length);

	/** 
	*
	* 	func name	:	seekFile
	*	@brief		:	文件定位
	*	@param		:	t_int64 & offset
	*	@param		:		    
	*	@return		:	E_OK  E_FAIL
	*	@author		:	chenjiang 
	*	@note		:	可调用此函数实现文件指针的偏移，如现在读指针位置为文件开头，
	*				     调用此函数，即可将读指针跳转到设置的偏移量的位置
	*
	*/
	t_int32 seekFile(t_int32 &offset);

	/** 
	*
	* 	func name	:		mkTempFile
	*	@brief		:	    创建临时文件
	*	@param		:		stringI & temp路径
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:			
	*
	*/
	t_int32 mkTempFile(t_int8 **temp);

	/** 
	* 	func name	:		strCount
	*	@brief		:	    获取文件中某个字符串出现的次数
	*	@param		:		const t_int8 * str，需要统计的字符串
	*	@param		:		t_int32 & count，字符串出现的次数
	*	@return		:		E_OK  E_FAIL
	*	@author		:		chenjiang modify
	*	@note:			
	*
	*/
	t_int32 strCount(const t_int8* str, t_int32& count);
	
	/** 
	*
	* 	func name	:		writeFile
	*	@brief		:	    写文件
	*	@param		:	    stringI &strBuff要写入文件的数据
	*	@param		:		t_int8 *mode :写入模式，默认为'a'
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*	@modify		:		hehairan将第二个参数(const t_int8 *mode = "a")去掉
	*/
	t_int32 writeFile(stringI &strBuff);

	/** 
	*
	* 	func name	:		readFile
	*	@brief		:	    写文件
	*	@param		:		stringI &strBuff，读取数据的缓冲区
	*	@param		:		t_int64 &size，读取数据的长度
	*	@return		:		t_int32
	*	@author		:	    E_OK  E_FAIL 
	*	@note		:			
	*
	*/
	t_int32 readFile(stringI &strBuff, t_int32 &size);

	/** 
	*
	* 	func name	:		getFp
	*	@brief		:	    获取文件句柄
	*	@param		:		t_int32 &fp，获取的文件句柄
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 getFp(FILE **fp);

	/** 
	* 	func name	:		fileFflush
	*	@brief		:	    将缓冲区的数据写入文件
	*	@return		:		E_OK  E_FAIL
	*	@author		:		chenjiang modify
	*	@note:			
	*
	*/
	t_int32 fileFlush();

	/** 
	*
	* 	func name	:		getFileSize
	*	@brief		:	    获取文件长度
	*	@param		:		t_int64 *fileSize，获取的文件长度
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 getFileSize(t_int32 *fileSize);

	/** 
	*
	* 	func name	:		setFileSize
	*	@brief		:	    设置文件长度
	*	@param		:		t_int64 fileSize，设置的文件长度
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 setFileSize(t_int32 fileSize);

	/** 
	*
	* 	func name	:		getFilePath
	*	@brief		:	    获取文件路径
	*	@param		:		stringI &filePath，获取的文件路径
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 getFilePath(stringI &filePath);

	/** 
	*
	* 	func name	:		setFilePath
	*	@brief		:	    设置文件路径
	*	@param		:		stringI &filePath，设置的文件路径
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 setFilePath(stringI &filePath);

	/** 
	*
	* 	func name	:		setFileLeafName
	*	@brief		:	    设置文件名
	*	@param		:		stringI &leafName，获取的文件名	    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 setFileLeafName(stringI &leafName);

	/** 
	*
	* 	func name	:		getFileLeafName
	*	@brief		:	    获取文件名
	*	@param		:		stringI &leafName，获取的文件名
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 getFileLeafName(stringI &leafName);

	/** 
	*
	* 	func name	:		isExist
	*	@brief		:	    判断文件是否存在
	*	@param		:		result:返回结果
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 isExist(t_bool *result);

	/** 
	*
	* 	func name	:		isWritable
	*	@brief		:	    判断文件是否可写
	*	@param		:		result:返回结果
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:		目前未实现	
	*
	*/
	t_int32 isWritable(t_bool *result);

	/** 
	*
	* 	func name	:		isExecutable
	*	@brief		:	    判断文件是否？？？
	*	@param		:		result:返回结果
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:	    目前未实现
	*
	*/
	t_int32 isExecutable(t_bool *result);

	/** 
	*
	* 	func name	:		isFile
	*	@brief		:	    判断是否是文件
	*	@param		:		t_bool *result，判断的结果
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*/
	t_int32 isFile(t_bool *result);

	/** 
	*
	* 	func name	:		isDirectory
	*	@brief		:	    判断是否是目录
	*	@param		:	    t_bool *result，判断的结果
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*/
	t_int32 isDirectory(t_bool *result);

	/** 
	* 	func name	:	dllopen
	*	@brief		:	打开目标路径下的dll库文件
	*	@param		:	void* dll库文件句柄;
	*	@return		:	void
	*	@author		:	zhang_xusheng
	*	@note		:	modified on 2013-4-21
	*
	*/
	void* dllopen(const t_int8* libPath);

	/** 
	* 	func name	:	dllsym
	*	@brief		:	检索指定动态库中的输出函数地址
	*	@param		:	handle： dll库文件句柄;symbol:动态库路径
	*	@return		:	void
	*	@author		:	zhang_xusheng
	*	@note		:	modified on 2013-4-21
	*
	*/
	void* dllsym(void *handle, const t_int8 *symbol);

	/** 
	* 	func name	:	dllclose
	*	@brief		:	关闭dll动态库
	*	@param		:	handle： dll库文件句柄;
	*	@return		:	void
	*	@author		:	zhang_xusheng
	*	@note		:	modified on 2013-8-31
	*
	*/
	void dllclose(void *handle);

#ifdef WIN32

#else
	t_int32 isSymLink(t_bool *result);
#endif

	/** 
	* 	func name	:	getParent
	*	@brief		:	获取文件当前目录
	*	@param		:	fileI &parent
	*	@return		:	void
	*	@author		:	chenjiang
	*	@note		:	未实现，
	*
	*/
	t_int32 getParent(fileI &parent);

	/** 
	* 	func name	:	getDirectory
	*	@brief		:   创建目录
	*	@param		:	directoryI **result
	*	@param		:		
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 getDirectory(directoryI **result);

	/** 
	* 	func name	:	load
	*	@brief		:	获取动态库的函数
	*	@param		:	modulesLibrary **result获取的动态库
	*	@param		:		
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 load(modulesLibrary **result);

	/** 
	* 	func name	:	findFunctionSymbol
	*	@brief		:	获取动态库的函数
	*	@param		:	modulesLibrary *mLibrary
	*	@param		:	t_int8 *symbol函数名称
	*	@param		:   void **result获取的函数的地址
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 findFunctionSymbol(modulesLibrary *mLibrary, t_int8 *symbol, void **result);

private:

	/** 
	* 	func name	:	parsePath
	*	@brief		:	把传入的文件路径转换成适合当前平台的路径结构
	*	@return		:	char*
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	stringI parsePath(const stringI &path);

	/** 
	* 	func name	:	loadLibrary
	*	@brief		:	获取动态库的函数
	*	@param		:	modulesLibrary **result获取的动态库
	*	@param		:	name:动态库名	
	*	@return		:	E_OK/E_FAIL	
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 loadLibrary(const t_int8 *name, modulesLibrary **result);

	/** 
	* 	func name	:	getFileStat
	*	@brief		:   获取文件stat
	*	@param		:		
	*	@param		:		
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 getFileStat();

	/** 
	* 	func name	:	getLinkStat
	*	@brief		:   获取链接文件stat
	*	@param		:		
	*	@param		:		
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 getLinkStat();

private:
	OS_FILE::os_stat mFileStat;
	t_int32 ii;
	stringI mPath;
	stringI mLeafName;

	t_int32 mm;
	FILE *mFp;
	t_int32 ss;
};

#endif
