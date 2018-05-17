/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file	:			config_i.h
 * 	@brief	:			config_i.h定义了configJson,configXml,configIni类，
                    完成读取配置文件的功能，目前支持json
 * 	@author	:         chenjiang
 *	@note	:	
 *	@modify	:         hehairan add注释头
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
	*	@brief		:	把配置文件信息加载到keyValueI中，读取配置文件内容，保存到keyValueI变量中
	*	@param		:	const stringI &confPath，文件所在的路径
	*	@return		:   E_OK,函数执行成功, E_FAIL:失败
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
	*	@brief		:	配置信息写到文件中，json格式
	*	@param		:	const stringI &confPath，文件所在的路径
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:   2013-1-10 
	*	@note:			
	*
	*/
	t_int32 saveConf( const stringI &confPath );

	/** 
	*
	* 	func name	:	fastSaveConf
	*	@brief		:	快速把配置信息写到文件中，json格式
	*	@param		:	const stringI &confPath，文件所在的路径
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:   2013-1-10 
	*	@note:			
	*
	*/
	t_int32 fastSaveConf(const stringI &confPath);

	/** 
	*
	* 	func name	:	getValue
	*	@brief		:	在root中，根据key获取key对应的值
	*	@param		:	const keyValueI &root，keyValueI类型的节点，stringI &key，键，keyValueI &value，key对应的值，为keyValueI类型  
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 getValue(const keyValueI &root, const t_int8 *key, keyValueI &value);

	/** 
	*
	* 	func name	:	setValue
	*	@brief		:	在root中，设置key对应的值
	*	@param		:	keyValueI &root需要设置键值的keyValueI，stringI &key键，stringI &value,key对应的值 
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 setValue(keyValueI &root, stringI &key, stringI &value);

	/** 
	*
	* 	func name	:	getKeyValue
	*	@brief		:	获取加载配置文件后的信息
	*	@param		:	keyValueI &keyValue需要设置键值的keyValueI
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 getKeyValue(keyValueI &keyValue);

	/** 
	*
	* 	func name	:	setKeyValue
	*	@brief		:	重新设置KeyValueI
	*	@param		:	const stringI & kValue:json格式的字符串
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 setKeyValue(const stringI &kValue);

	/** 
	*
	* 	func name	:	setKeyValue
	*	@brief		:	重新设置KeyValueI
	*	@param		:	const keyValueI& kValue:keyValueI类型的，也就是json信息
	*	@return		:   t_int32,函数执行成功或失败
	*	@author		:   chenjiang
	*   @date		:    2013-1-10 
	*	@note:			
	*
	*/
	t_int32 setKeyValue(const keyValueI &kValue);
	
	/** 
	*
	* 	func name	:	strToKeyValue
	*	@brief		:	把字符串str转变成keyValueI类型的数据
	*	@param		:	const t_int8 *str 字符串,keyValueI &keyValue转变后的数据
	*	@return		:   t_int32,函数执行成功或失败
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

