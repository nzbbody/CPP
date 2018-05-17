/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _LUA_IMPL_H
#define _LUA_IMPL_H

#include <lua_i.h>
#include <modules/modules_manager_i.h>
#include <string>
#include <memory_i.h>
class luaImpl : public luaI
{
	DECLARE_SUPPORTI

public:
	static modulesManagerI *mgr;
public:
	virtual t_int32 open(const char* luaFile);
	virtual t_int32 getValue(const t_int8* para, t_int32* value);
	virtual t_int32 getValue(const t_int8* para, t_int8** value);
	virtual t_int8* doLuaFun(char *luaFunName, const t_int8* arg);
	virtual void 	bindLuaFun(csumCb localFun, const t_int8* luaFunName);
	virtual t_int32 luaClose(void);
	lua_State* 		getLuaState(void);
	template<typename T> t_int32 doLuaFun1(char *luaFunName,T a)
	{
		t_int8 *temparg = NULL;
		t_int8 *retstr=NULL;

		lua_getglobal(pluaState,luaFunName);
		if(a)
		{
			Push(a);	
		}
		
		int ret=0;
		const char* tempstr=NULL;
		ret = lua_pcall(pluaState,1,1,0) ;
		if ( ret != 0 )
		{		
			traceErr(RED"lua_pcall err:%s",lua_tostring(pluaState,-1)) ;
			lua_pop(pluaState,1) ;
			return NULL;
		}
		tempstr = lua_tostring(pluaState,-1);

		if(tempstr)
		{
			retstr = (char*)mallocI((strlen(tempstr)+1)*sizeof(char));
			strcpy(retstr,tempstr);	
		}
		else
		{
			retstr = NULL;	
		}

		lua_pop(pluaState,1) ;

		return E_OK;
	}
public:
/** Push函数
*
* 	func name:	Push
*	@brief:		将指定数据压栈，根据参数的不同分别进行重载
*	@param:		void
*	@param:		void
*	@return:	void
*	@author:	zhang_xusheng
*	@note:		
*
*/
	inline void Push()
	{
		lua_pushnil(pluaState);
	}
	inline void Push(const char* param)
	{
		lua_pushstring(pluaState, param);
	}
	inline void Push(const std::string& param)
	{
		lua_pushlstring(pluaState, param.c_str(), param.size());
	}
	inline void Push(int param)
	{
		lua_pushnumber(pluaState, param);
	}
	inline void Push(double param)
	{
		lua_pushnumber(pluaState, param);
	}
	inline void Push(bool param)
	{
		lua_pushboolean(pluaState, param);
	}
	inline void Push(lua_CFunction  param)
	{
		lua_pushcfunction(pluaState, param);
	}
private:
	lua_State *pluaState;		/**LUA虚拟机的句柄*/

};

#endif

