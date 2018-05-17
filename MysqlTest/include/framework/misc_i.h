/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			misc_i.h
* 	@brief	:			misc_i.h主要提供位的操作相关函数及获取IP和设置休眠函数
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan add注释头
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
		 *	@output		:	endian = 1,为小端，endian＝0为大端
		 *   @return	:	返回E_OK E_FAIL
		 *	@author		:	xu_xiangdong
		 *	@note		:	大小端判断函数
		 *
		 */
		static t_int32 byteOrder (t_int32 *endian);

		/** 
		*
		* 	func name	:	bswap_16
		*	@input		:	x-- 要转换的数据
		*	@output		:	para--转换后的数据
		*   @return		:	返回E_OK
		*	@author		:	xu_xiangdong
		*	@note:			
		*
		*/
		static t_int32 bswap_16(t_uint16 x,t_uint16 &para);
		static t_uint16 bswap_16(t_uint16 x);
		/** 
		*
		* 	func name	:	bswap_32
		*	@brief		:	大小端数据转换(2字节)
		*	@input		:	x-- 要转换的数据
		*	@output		:	para--转换后的数据
		*   @return		:	返回E_OK
		*	@author		:	xu_xiangdong
		*	@note:			
		*
		*/	
		static t_int32 bswap_32(t_uint32 x,t_uint32 &para); 
		static t_uint32 bswap_32(t_uint32 x);
		/** 
		*
		* 	func name	:	setBit
		*	@brief		:	置位
		*	@input		:	nr-- 要置位的位数
		*	@input		:	addr--指向要进行置位的变量的指针
		*   @return		:	返回E_OK
		*	@author		:	zhangsunbo(xu_xiangdong)
		*	@note:			
		*
		*/
		static t_int32 setBit(t_uint32 nr, void *addr);

		/** 
		*
		* 	func name	:	setBit
		*	@brief		:	复位
		*	@input		:	nr-- 要复位的位数
		*	@input		:	addr--指向要进行复位的变量的指针
		*   @return		:	返回E_OK
		*	@author		:	zhangsunbo(xu_xiangdong)
		*	@note:			
		*
		*/
		static t_int32 clearBit(t_uint32 nr, void *addr);

		/** 
		*
		* 	func name	:	readBit
		*	@brief		:	复位
		*	@input		:	nr-- 要复位的位数
		*	@input		:	addr--指向要进行复位的变量的指针
		*	@output		:	oldVal--保存位值
		*   @return		:	返回E_OK
		*	@author		:	zhangsunbo(xu_xiangdong)
		*	@note:			
		*
		*/	
		static t_int32 readBit(t_uint32 nr, void *addr, t_int32 &oldVal);
};

/** 
*
* 	func name	:	getHostIp
*	@brief		:	获取主机IP
*	@input		:	NULL
*   @return		:	返回字符串类型的IP地址
*	@author		:	zhangxusheng
*	@note:			2013-3-30
*
*/	
t_int8 DLL_EXPORT* getHostIp(t_int8* ifrname = "eth0");

/** 
*
* 	func name	:	plat_sleep
*	@brief		:	跨平台的sleep
*	@input		:	time：时间(毫秒)
*   @return		:	成功返回E_OK
*	@author		:	zhangxusheng
*	@note:			2013-3-30
*
*/	
t_int32 DLL_EXPORT plat_sleep(t_int32 num);	
void DLL_EXPORT delay_loop(t_uint32 usec);
/** 
*
* 	func name	:	ipcheck
*	@brief		:	ip合法性检查
*	@input		:	ip字符串
*   @return		:	E_OK：合法字符串，E_FAIL：不合法字符串
*	@author		:	zhangxusheng
*	@note:			2013-3-30
*
*/	
t_int32 DLL_EXPORT ipcheck(t_int8* ip);

/** 
*
* 	func name:	show_version
*	@brief:			打印库的编译时间和版本
*	@input:		void
*   @return:		成功返回E_OK
*	@author:		zhangxusheng
*	@note:			2013-8-13
*
*/
t_int32 show_version();


#endif

