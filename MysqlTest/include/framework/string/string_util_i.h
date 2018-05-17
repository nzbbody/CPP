/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file	:		string_util_i.h
 * 	@brief	:		edp_errcode.h������stringUtilI�࣬����ַ�������Ĺ���
 * 	@author	:		chenjiang
 *	@modify	:		hehairan add ע��
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
	*	@brief		:	ͳ���ַ���str��sub���ֵĴ���
	*	@param		:	str ԭʼ���ַ���
	*	@param		:	sub ��Ҫͳ�Ƶ��ַ���
	*	@param		:	count: sub���ֵĴ���
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
	*	@brief		:	�ַ�����ʽ��
	*	@param		:	t_int8 *fmt ��ʽ���ַ��� (��"%d,%s,%d")
	*	@param		:	va_list vars���ɱ����
	*	@return		:   ת������ַ���
	*	@author		:   chenjiang
	*   @date		:   2012-12-18 
	*	@note		:			
	*
	*/
	static stringI format(t_int8 *fmt, va_list vars);

	/** 
	*
	* 	func name	:	subString
	*	@brief		:	��ȡ�ַ���str��startIndex��endIndex���Ӵ�
	*	@input		:	startIndex ��ʼλ��
	*	@input		:	endIndex ����λ��
	*	@input		:	const stringI &srcStr ԭʼ���ַ���
	*	@output		:	subStr ����ȡ���Ӵ�
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
	*	@brief		:	��ȡ�ַ���str��startIndex��endIndex���Ӵ�
	*	@input		:	startIndex ��ʼλ��
	*	@input		:	endIndex ����λ��
	*	@input		:	t_int8* srcStr  ԭʼ���ַ���
	*	@output		:	subStr ����ȡ���Ӵ�
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
	*	@brief		:	���ַ���str��ɴ�д
	*	@input		:	stringI &str ��Ҫת�����ַ���
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
	*	@brief		:	���ַ���str��ɴ�д
	*	@input		:	t_int8* str ��Ҫת�����ַ���
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
	*	@brief		:	���ַ���תΪСд
	*	@input		:	stringI &str ��Ҫת�����ַ���
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
	*	@brief		:	���ַ���תΪСд
	*	@input		:	t_int8* str ��Ҫת�����ַ���
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
	*	@brief		:	���ַ������ߵĿո�ȥ��
	*	@input		:	stringI &str,��Ҫ������ַ���
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
	*	@brief		:	���ַ������ߵĿո�ȥ��
	*	@input		:	t_int8* str,��Ҫ������ַ���
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
*	@brief		:	����ת����������inValue���͵�tת����outType����
*	@param		:	const inValue& t����Ҫת��������
*	@return		:   outType,ת����Ŀ������
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
*	@brief		:	    ��int�͵�����ת���ַ���
*	@param		:		data ��Ҫת��������
*	@param		:		str ת���ɵ��ַ���
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
*	@brief		:	���ַ���ת������
*	@param		:	const stringI &str,��Ҫ������ַ���
*	@param		:	t_float64 &data,ת���������
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

