/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file	:		string_util_i.h
 * 	@brief	:		edp_errcode.h定义了stringUtilI类，完成字符串处理的功能
 * 	@author	:		chenjiang
 *	@modify	:		hehairan add 注释
 *	@note:	
 */

#ifndef _STRING_UTIL_I_H
#define _STRING_UTIL_I_H

#include <data_types.h>
#include <string/string_i.h>
#include <sstream>
#include <errno/error_i.h>

using namespace std;


class stringUtilI
{
private:
	template<class outType, class inValue>
	static outType convent(const inValue& t);
public:
	/** 
	*
	* 	func name	:	getCount
	*	@brief		:	统计字符串str中sub出现的次数
	*	@param		:	str 原始的字符串
	*	@param		:	sub 需要统计的字符串
	*	@param		:	count: sub出现的次数
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 getCount(const t_int8* str, const t_int8* sub, t_int32& count);

	/** 
	*
	* 	func name	:	format
	*	@brief		:	字符串格式化
	*	@param		:	t_int8 *fmt 格式化字符串 (如"%d,%s,%d")
	*	@param		:	va_list vars：可变参数
	*	@return		:   转换后的字符串
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static stringI format(t_int8 *fmt, va_list vars);

	/** 
	*
	* 	func name	:	subString
	*	@brief		:	获取字符串str从startIndex到endIndex的子串
	*	@input		:	startIndex 开始位置
	*	@input		:	endIndex 结束位置
	*	@input		:	const stringI &srcStr 原始的字符串
	*	@output		:	subStr ：获取的子串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 subString(t_int32 startIndex, t_int32 endIndex, const stringI &srcStr, stringI &subStr);
	
	/** 
	*
	* 	func name	:	subString
	*	@brief		:	获取字符串str从startIndex到endIndex的子串
	*	@input		:	startIndex 开始位置
	*	@input		:	endIndex 结束位置
	*	@input		:	t_int8* srcStr  原始的字符串
	*	@output		:	subStr ：获取的子串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 subString(t_int32 startIndex, t_int32 endIndex, const t_int8* srcStr, stringI &subStr);
	
	/** 
	*
	* 	func name	:	toUpperCase
	*	@brief		:	把字符串str变成大写
	*	@input		:	stringI &str 需要转换的字符串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 toUpperCase(stringI &str);

	/** 
	*
	* 	func name	:	toUpperCase
	*	@brief		:	把字符串str变成大写
	*	@input		:	t_int8* str 需要转换的字符串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 toUpperCase(t_int8* str);
	
	/** 
	*
	* 	func name	:	toLowerCase
	*	@brief		:	把字符串转为小写
	*	@input		:	stringI &str 需要转换的字符串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 toLowerCase(stringI &str);

	/** 
	*
	* 	func name	:	toLowerCase
	*	@brief		:	把字符串转为小写
	*	@input		:	t_int8* str 需要转换的字符串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 toLowerCase(t_int8* str);
	
	/** 
	*
	* 	func name	:	trimSpace
	*	@brief		:	把字符串两边的空格去掉
	*	@input		:	stringI &str,需要处理的字符串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 trimSpace(stringI &str);

	/** 
	*
	* 	func name	:	trimSpace
	*	@brief		:	把字符串两边的空格去掉
	*	@input		:	t_int8* str,需要处理的字符串
	*	@return		:   E_OK/ E_FAIL
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static t_int32 trimSpace(t_int8* str);

	template<class dataType>
	static t_int32 numToStr(const dataType &data, stringI &str);
	
	template<class strType, class dataType>
	static t_int32 strToNum(const strType &str, dataType &data);
	
};

/** 
*
* 	func name	:	convent
*	@brief		:	类型转换函数，把inValue类型的t转换成outType类型
*	@param		:	const inValue& t，需要转换的类型
*	@return		:   outType,转换的目标类型
*	@author		:   chenjiang
*   @date		:    2012-12-18 
*	@note:			
*
*/
template<class outType, class inValue>
outType stringUtilI::convent(const inValue& t)
{
	stringstream stream;
	stream.clear();
	stream << t;
	outType result;
	stream >> result;
	return result;
}

/** 
*
* 	func name	:		numToStr
*	@brief		:	    把int型的数字转成字符串
*	@param		:		data 需要转换的数字
*	@param		:		str 转换成的字符串
*	@return		:		t_int32
 *	@author		:	    chenjiang 2012-12-19
*	@note:			
*
*/
template<class dataType>
t_int32 stringUtilI::numToStr(const dataType &data, stringI &str)
{
	str = convent<stringI>(data);
	return E_OK;
}

/** 
*
* 	func name	:	strToNum
*	@brief		:	把字符串转成数字
*	@param		:	const stringI &str,需要处理的字符串
*	@param		:	t_float64 &data,转化后的数字
*	@return		:   t_int32
*	@author		:   chenjiang
*   @date		:   2012-12-19 
*	@note:			
*
*/
template<class strType, class dataType>
t_int32 stringUtilI::strToNum(const strType &str, dataType &data)
{
	data = convent<dataType>(str);
	return E_OK;
}

#endif 

