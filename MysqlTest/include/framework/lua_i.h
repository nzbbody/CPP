/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _LUA_I_H
#define _LUA_I_H

#include <modules/support_i.h>
#include <modules/modules_i.h>
#include <modules/modules_manager_i.h>
#include <errno/error_i.h>
#include <trace/trace_i.h>

extern "C" 
{ 
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
} 

#define LUA_I_NAME "lua interface name"
#define LUA_I_MID {"lua interface mid",}

typedef int (*csumCb)(lua_State* );

#define ARGEND "LUAARGEND"

class luaI : public supportI
{		
public:
	virtual t_int32 open(const char* luaFile) = 0;
	virtual t_int32 getValue(const t_int8* para, t_int32* value) = 0;
	virtual t_int32 getValue(const t_int8* para, t_int8** value) = 0;
	virtual t_int8* doLuaFun(char *luaFunName, const t_int8* arg)	=0;
	virtual void bindLuaFun(csumCb localFun, const t_int8* luaFunName)	=0;
	virtual t_int32 luaClose(void) = 0;	
	DECLARE_MODULE_IID(LUA_I_MID)
};

DEFINE_MODULE_IID(luaI, LUA_I_MID)

#endif

