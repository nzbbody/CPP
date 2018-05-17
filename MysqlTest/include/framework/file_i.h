/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			file_i.h
* 	@brief	:			�ṩ�ļ���ز����ӿں���
* 	@author	:           chenjiang
*	@note	:	
*	@modify	:           hehairan addע��ͷ
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
*	@brief		:	    ��Ҫ�ṩ���ļ������Ĺ��ܺ������紴�����򿪡��رա�ɾ�����ضϡ���д����ת
*						�ļ�·���������ȡ���ļ���С������
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
	*	@brief		:	    ���캯��
	*	@param		:		
	*	@return		:		��
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	fileI();

	/** 
	*
	* 	func name	:		fileI
	*	@brief		:	    ���캯��
	*	@param		:		stringI &path �ļ�·��
	*	@return		:		
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	fileI(const stringI &path);

	/** 
	*
	* 	func name	:		~fileI
	*	@brief		:	    ��������
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
	*	@brief		:	    �ļ���������������
	*	@param		:		t_int32 type�����ļ�����
	*	@param		:		t_int32 permissons�����ļ�Ȩ��
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 createFile();

	/** 
	*
	* 	func name	:		openFile
	*	@brief		:	    ���ļ�
	*	@param		:	    const t_int8* mode,���ļ��ķ�ʽ������˵"r" "r+" "rw"
	*	@return		:	 	E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 openFile( const t_int8* mode );

	/** 
	*
	* 	func name	:		closeFile
	*	@brief		:	        �ر��ļ�
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
	*	@brief		:	    ɾ���ļ�
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
	*	@brief		:	    �ض��ļ�
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
	*	@brief		:	�ļ���λ
	*	@param		:	t_int64 & offset
	*	@param		:		    
	*	@return		:	E_OK  E_FAIL
	*	@author		:	chenjiang 
	*	@note		:	�ɵ��ô˺���ʵ���ļ�ָ���ƫ�ƣ������ڶ�ָ��λ��Ϊ�ļ���ͷ��
	*				     ���ô˺��������ɽ���ָ����ת�����õ�ƫ������λ��
	*
	*/
	t_int32 seekFile(t_int32 &offset);

	/** 
	*
	* 	func name	:		mkTempFile
	*	@brief		:	    ������ʱ�ļ�
	*	@param		:		stringI & temp·��
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:			
	*
	*/
	t_int32 mkTempFile(t_int8 **temp);

	/** 
	* 	func name	:		strCount
	*	@brief		:	    ��ȡ�ļ���ĳ���ַ������ֵĴ���
	*	@param		:		const t_int8 * str����Ҫͳ�Ƶ��ַ���
	*	@param		:		t_int32 & count���ַ������ֵĴ���
	*	@return		:		E_OK  E_FAIL
	*	@author		:		chenjiang modify
	*	@note:			
	*
	*/
	t_int32 strCount(const t_int8* str, t_int32& count);
	
	/** 
	*
	* 	func name	:		writeFile
	*	@brief		:	    д�ļ�
	*	@param		:	    stringI &strBuffҪд���ļ�������
	*	@param		:		t_int8 *mode :д��ģʽ��Ĭ��Ϊ'a'
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*	@modify		:		hehairan���ڶ�������(const t_int8 *mode = "a")ȥ��
	*/
	t_int32 writeFile(stringI &strBuff);

	/** 
	*
	* 	func name	:		readFile
	*	@brief		:	    д�ļ�
	*	@param		:		stringI &strBuff����ȡ���ݵĻ�����
	*	@param		:		t_int64 &size����ȡ���ݵĳ���
	*	@return		:		t_int32
	*	@author		:	    E_OK  E_FAIL 
	*	@note		:			
	*
	*/
	t_int32 readFile(stringI &strBuff, t_int32 &size);

	/** 
	*
	* 	func name	:		getFp
	*	@brief		:	    ��ȡ�ļ����
	*	@param		:		t_int32 &fp����ȡ���ļ����
	*	@param		:		    
	*	@return		:		E_OK  E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 getFp(FILE **fp);

	/** 
	* 	func name	:		fileFflush
	*	@brief		:	    ��������������д���ļ�
	*	@return		:		E_OK  E_FAIL
	*	@author		:		chenjiang modify
	*	@note:			
	*
	*/
	t_int32 fileFlush();

	/** 
	*
	* 	func name	:		getFileSize
	*	@brief		:	    ��ȡ�ļ�����
	*	@param		:		t_int64 *fileSize����ȡ���ļ�����
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
	*	@brief		:	    �����ļ�����
	*	@param		:		t_int64 fileSize�����õ��ļ�����
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
	*	@brief		:	    ��ȡ�ļ�·��
	*	@param		:		stringI &filePath����ȡ���ļ�·��
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
	*	@brief		:	    �����ļ�·��
	*	@param		:		stringI &filePath�����õ��ļ�·��
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
	*	@brief		:	    �����ļ���
	*	@param		:		stringI &leafName����ȡ���ļ���	    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*
	*/
	t_int32 setFileLeafName(stringI &leafName);

	/** 
	*
	* 	func name	:		getFileLeafName
	*	@brief		:	    ��ȡ�ļ���
	*	@param		:		stringI &leafName����ȡ���ļ���
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
	*	@brief		:	    �ж��ļ��Ƿ����
	*	@param		:		result:���ؽ��
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
	*	@brief		:	    �ж��ļ��Ƿ��д
	*	@param		:		result:���ؽ��
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:		Ŀǰδʵ��	
	*
	*/
	t_int32 isWritable(t_bool *result);

	/** 
	*
	* 	func name	:		isExecutable
	*	@brief		:	    �ж��ļ��Ƿ񣿣���
	*	@param		:		result:���ؽ��
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note		:	    Ŀǰδʵ��
	*
	*/
	t_int32 isExecutable(t_bool *result);

	/** 
	*
	* 	func name	:		isFile
	*	@brief		:	    �ж��Ƿ����ļ�
	*	@param		:		t_bool *result���жϵĽ��
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*/
	t_int32 isFile(t_bool *result);

	/** 
	*
	* 	func name	:		isDirectory
	*	@brief		:	    �ж��Ƿ���Ŀ¼
	*	@param		:	    t_bool *result���жϵĽ��
	*	@param		:		    
	*	@return		:		E_OK/E_FAIL
	*	@author		:	    chenjiang 
	*	@note:			
	*/
	t_int32 isDirectory(t_bool *result);

	/** 
	* 	func name	:	dllopen
	*	@brief		:	��Ŀ��·���µ�dll���ļ�
	*	@param		:	void* dll���ļ����;
	*	@return		:	void
	*	@author		:	zhang_xusheng
	*	@note		:	modified on 2013-4-21
	*
	*/
	void* dllopen(const t_int8* libPath);

	/** 
	* 	func name	:	dllsym
	*	@brief		:	����ָ����̬���е����������ַ
	*	@param		:	handle�� dll���ļ����;symbol:��̬��·��
	*	@return		:	void
	*	@author		:	zhang_xusheng
	*	@note		:	modified on 2013-4-21
	*
	*/
	void* dllsym(void *handle, const t_int8 *symbol);

	/** 
	* 	func name	:	dllclose
	*	@brief		:	�ر�dll��̬��
	*	@param		:	handle�� dll���ļ����;
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
	*	@brief		:	��ȡ�ļ���ǰĿ¼
	*	@param		:	fileI &parent
	*	@return		:	void
	*	@author		:	chenjiang
	*	@note		:	δʵ�֣�
	*
	*/
	t_int32 getParent(fileI &parent);

	/** 
	* 	func name	:	getDirectory
	*	@brief		:   ����Ŀ¼
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
	*	@brief		:	��ȡ��̬��ĺ���
	*	@param		:	modulesLibrary **result��ȡ�Ķ�̬��
	*	@param		:		
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 load(modulesLibrary **result);

	/** 
	* 	func name	:	findFunctionSymbol
	*	@brief		:	��ȡ��̬��ĺ���
	*	@param		:	modulesLibrary *mLibrary
	*	@param		:	t_int8 *symbol��������
	*	@param		:   void **result��ȡ�ĺ����ĵ�ַ
	*	@return		:	E_OK/E_FAIL
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 findFunctionSymbol(modulesLibrary *mLibrary, t_int8 *symbol, void **result);

private:

	/** 
	* 	func name	:	parsePath
	*	@brief		:	�Ѵ�����ļ�·��ת�����ʺϵ�ǰƽ̨��·���ṹ
	*	@return		:	char*
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	stringI parsePath(const stringI &path);

	/** 
	* 	func name	:	loadLibrary
	*	@brief		:	��ȡ��̬��ĺ���
	*	@param		:	modulesLibrary **result��ȡ�Ķ�̬��
	*	@param		:	name:��̬����	
	*	@return		:	E_OK/E_FAIL	
	*	@author		:	chenjiang modify
	*	@note:			
	*
	*/
	t_int32 loadLibrary(const t_int8 *name, modulesLibrary **result);

	/** 
	* 	func name	:	getFileStat
	*	@brief		:   ��ȡ�ļ�stat
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
	*	@brief		:   ��ȡ�����ļ�stat
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
