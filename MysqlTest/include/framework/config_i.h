/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file	:			config_i.h
 * 	@brief	:			config_i.h������configJson,configXml,configIni�࣬
                    ��ɶ�ȡ�����ļ��Ĺ��ܣ�Ŀǰ֧��json
 * 	@author	:         chenjiang
 *	@note	:	
 *	@modify	:         hehairan addע��ͷ
 */

#ifndef _CONFIG_I_H
#define _CONFIG_I_H

#include <data_types.h>
#include <string/string_i.h>
#include <key_value_i.h>
#include <my_json/json.h>


class configJson 
{
public:
	 configJson();
	 ~configJson();
	 
public:

	/** 
	*
	* 	func name	:	loadConf
	*	@brief		:	�������ļ���Ϣ���ص�keyValueI�У���ȡ�����ļ����ݣ����浽keyValueI������
	*	@param		:	const stringI &confPath���ļ����ڵ�·��
	*	@return		:   E_OK,����ִ�гɹ�, E_FAIL:ʧ��
	*	@author		:   chenjiang
	*   @date		:   2013-1-10 
	*	@note:			
	*
	*/
	t_int32 loadConf( const stringI &confPath );


	t_int32 defaultConfig(stringI &confPath, keyValueI &confValue);

	/** 
	*
	* 	func name	:	saveConf
	*	@brief		:	������Ϣд���ļ��У�json��ʽ
	*	@param		:	const stringI &confPath���ļ����ڵ�·��
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:   2013-1-10 
	*	@note:			
	*
	*/
	t_int32 saveConf( const stringI &confPath );

	/** 
	*
	* 	func name	:	fastSaveConf
	*	@brief		:	���ٰ�������Ϣд���ļ��У�json��ʽ
	*	@param		:	const stringI &confPath���ļ����ڵ�·��
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:   2013-1-10 
	*	@note:			
	*
	*/
	t_int32 fastSaveConf(const stringI &confPath);

	/** 
	*
	* 	func name	:	getValue
	*	@brief		:	��root�У�����key��ȡkey��Ӧ��ֵ
	*	@param		:	const keyValueI &root��keyValueI���͵Ľڵ㣬stringI &key������keyValueI &value��key��Ӧ��ֵ��ΪkeyValueI����  
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 getValue(const keyValueI &root, const t_int8 *key, keyValueI &value);

	/** 
	*
	* 	func name	:	setValue
	*	@brief		:	��root�У�����key��Ӧ��ֵ
	*	@param		:	keyValueI &root��Ҫ���ü�ֵ��keyValueI��stringI &key����stringI &value,key��Ӧ��ֵ 
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 setValue(keyValueI &root, stringI &key, stringI &value);

	/** 
	*
	* 	func name	:	getKeyValue
	*	@brief		:	��ȡ���������ļ������Ϣ
	*	@param		:	keyValueI &keyValue��Ҫ���ü�ֵ��keyValueI
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 getKeyValue(keyValueI &keyValue);

	/** 
	*
	* 	func name	:	setKeyValue
	*	@brief		:	��������KeyValueI
	*	@param		:	const stringI & kValue:json��ʽ���ַ���
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 setKeyValue(const stringI &kValue);

	/** 
	*
	* 	func name	:	setKeyValue
	*	@brief		:	��������KeyValueI
	*	@param		:	const keyValueI& kValue:keyValueI���͵ģ�Ҳ����json��Ϣ
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 setKeyValue(const keyValueI &kValue);
	
	/** 
	*
	* 	func name	:	strToKeyValue
	*	@brief		:	���ַ���strת���keyValueI���͵�����
	*	@param		:	const t_int8 *str �ַ���,keyValueI &keyValueת��������
	*	@return		:   t_int32,����ִ�гɹ���ʧ��
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 strToKeyValue(const t_int8 *str, keyValueI &keyValue);
private:
//	keyValueI getKeyValueI( stringI & name, keyValueI &root );
	
private:
	keyValueI confValue;
};


class configXml 
{
public:
	configXml();
	~configXml();
private:
	
};

class configIni 
{
public:
	configIni();
	~configIni();

private:
	 
};


#endif

