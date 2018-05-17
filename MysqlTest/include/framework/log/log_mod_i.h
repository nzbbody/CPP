/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *@file:log_mod_i.h
 *
 * @description:
 *
 * @author:ning_shuanglong
 * 
 * @date:2013-01-11
 */

#ifndef _LOG_MOD_I_H
#define _LOG_MOD_I_H

#include <data_types.h>
#include <errno/error_i.h>
#include <string/string_i.h>

#define MOD_NAME(x) {x,#x}
#define MOD_SIZE 20

typedef struct _mod_str
{
	int id;
	const t_int8* name;
}MOD_STR;

typedef enum _mod_bit
{
	MOD1=1,
	MOD2=2,
}MOD_BIT;

#if 0
static MOD_STR modName[]=
{
	MOD_NAME(MOD1),
	MOD_NAME(MOD2),
	{-1,NULL}
};
#endif

class logModI
{
private:
	char modBitFlag[MOD_SIZE];
	MOD_STR modName[8*MOD_SIZE];
	
public:
	logModI()
	{
		int i = 0;
		memset(modBitFlag,0x0, MOD_SIZE);
		for( ; i < 8 * MOD_SIZE ; i++)
		{
			modName[i].id = -1;
			modName[i].name = NULL;
		}
	}

public:
	//根据ID获取模块名
	t_int32 getModName(t_int32 id, stringI & result);
	
	//使能moduleBit位置的模块
	t_int32 setModBit(t_int32 modulesBit);
	
	//清除moduleBit位置的模块
	t_int32 clrModBit(t_int32 modulesBit);

	//获取modulesBit位置的模块标志
	t_int32 getModBit(t_int32 modulesBit, t_int32 &resultBit);
	
	//根据模块名获取模块标志
	t_int32 getModBit(t_int8 *modname, t_int32 &resultBit);

	//根据模块名使能模块
	t_int32 enableMod(t_int8* modulesName);

	//根据模块名不是能模块
	t_int32 disableMod(t_int8* modulesName);

	//注册模块
	t_int32 regLogMod(const t_int8 *modname);
	
	//注销模块
	t_int32 unregLogMod(const t_int8 *modname);
	
};


#endif

