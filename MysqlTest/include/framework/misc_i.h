/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			misc_i.h
* 	@brief	:			misc_i.h��Ҫ�ṩλ�Ĳ�����غ�������ȡIP���������ߺ���
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan addע��ͷ
*/

#ifndef _MISC_I_H
#define _MISC_I_H

#include <data_types.h>
#include <errno/error_i.h>

#define BIT_TEST(bit, test) ((bit) & (test))
#define BIT_CLR(bit, clr) ((bit) &= ~(clr))
#define BIT_SET(bit, set) ((bit) |= (set))

class DLL_EXPORT miscI
{
	public:	
		miscI();
		 ~miscI();

		 /** 
		 *
		 * 	func name	:	byteOrder
		 *	@input		:		
		 *	@output		:	endian = 1,ΪС�ˣ�endian��0Ϊ���
		 *   @return	:	����E_OK E_FAIL
		 *	@author		:	xu_xiangdong
		 *	@note		:	��С���жϺ���
		 *
		 */
		static t_int32 byteOrder (t_int32 *endian);

		/** 
		*
		* 	func name	:	bswap_16
		*	@input		:	x-- Ҫת��������
		*	@output		:	para--ת���������
		*   @return		:	����E_OK
		*	@author		:	xu_xiangdong
		*	@note:			
		*
		*/
		static t_int32 bswap_16(t_uint16 x,t_uint16 &para);
		static t_uint16 bswap_16(t_uint16 x);
		/** 
		*
		* 	func name	:	bswap_32
		*	@brief		:	��С������ת��(2�ֽ�)
		*	@input		:	x-- Ҫת��������
		*	@output		:	para--ת���������
		*   @return		:	����E_OK
		*	@author		:	xu_xiangdong
		*	@note:			
		*
		*/	
		static t_int32 bswap_32(t_uint32 x,t_uint32 &para); 
		static t_uint32 bswap_32(t_uint32 x);
		/** 
		*
		* 	func name	:	setBit
		*	@brief		:	��λ
		*	@input		:	nr-- Ҫ��λ��λ��
		*	@input		:	addr--ָ��Ҫ������λ�ı�����ָ��
		*   @return		:	����E_OK
		*	@author		:	zhangsunbo(xu_xiangdong)
		*	@note:			
		*
		*/
		static t_int32 setBit(t_uint32 nr, void *addr);

		/** 
		*
		* 	func name	:	setBit
		*	@brief		:	��λ
		*	@input		:	nr-- Ҫ��λ��λ��
		*	@input		:	addr--ָ��Ҫ���и�λ�ı�����ָ��
		*   @return		:	����E_OK
		*	@author		:	zhangsunbo(xu_xiangdong)
		*	@note:			
		*
		*/
		static t_int32 clearBit(t_uint32 nr, void *addr);

		/** 
		*
		* 	func name	:	readBit
		*	@brief		:	��λ
		*	@input		:	nr-- Ҫ��λ��λ��
		*	@input		:	addr--ָ��Ҫ���и�λ�ı�����ָ��
		*	@output		:	oldVal--����λֵ
		*   @return		:	����E_OK
		*	@author		:	zhangsunbo(xu_xiangdong)
		*	@note:			
		*
		*/	
		static t_int32 readBit(t_uint32 nr, void *addr, t_int32 &oldVal);
};

/** 
*
* 	func name	:	getHostIp
*	@brief		:	��ȡ����IP
*	@input		:	NULL
*   @return		:	�����ַ������͵�IP��ַ
*	@author		:	zhangxusheng
*	@note:			2013-3-30
*
*/	
t_int8 DLL_EXPORT* getHostIp(t_int8* ifrname = "eth0");

/** 
*
* 	func name	:	plat_sleep
*	@brief		:	��ƽ̨��sleep
*	@input		:	time��ʱ��(����)
*   @return		:	�ɹ�����E_OK
*	@author		:	zhangxusheng
*	@note:			2013-3-30
*
*/	
t_int32 DLL_EXPORT plat_sleep(t_int32 num);	
void DLL_EXPORT delay_loop(t_uint32 usec);
/** 
*
* 	func name	:	ipcheck
*	@brief		:	ip�Ϸ��Լ��
*	@input		:	ip�ַ���
*   @return		:	E_OK���Ϸ��ַ�����E_FAIL�����Ϸ��ַ���
*	@author		:	zhangxusheng
*	@note:			2013-3-30
*
*/	
t_int32 DLL_EXPORT ipcheck(t_int8* ip);

/** 
*
* 	func name:	show_version
*	@brief:			��ӡ��ı���ʱ��Ͱ汾
*	@input:		void
*   @return:		�ɹ�����E_OK
*	@author:		zhangxusheng
*	@note:			2013-8-13
*
*/
t_int32 show_version();


#endif

