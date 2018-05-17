 //  "$Id: LuaWrap.h 1938 2006-02-20 07:54:38Z wanghw $"
//   (c) Copyright 1992-2005, ZheJiang Dahua Information Technology Stock CO.LTD.
//                            All Rights Reserved
//
//	文 件 名： LuaWrap.h
//	描    述:  LUA引擎的更高层封装
//	修改记录： 2005-8-22 Peter Wang <wanghw@dhmail.com> Initial Version
//            2006-1-18 王恒文 <wang_hengwen@dhmail.com> 增加了LUA线程得支持
//		      2006-2-20 王恒文 <wang_hengwen@dahuatech.com> 修正在gcc 3.2下面的编译错误
//

#ifndef __LUA_WRAP__
#define __LUA_WRAP__


#include "luaStack.h"
#include <assert.h>

/*
** macros for thread synchronization inside Lua core machine:
** all accesses to the global state and to global objects are synchronized.
** Because threads can read the stack of other threads
** (when running garbage collection),
** a thread must also synchronize any write-access to its own stack.
** Unsynchronized accesses are allowed only when reading its own stack,
** or when reading immutable fields from global objects
** (such as string values and udata values). 
*/
#ifndef lua_lock
#define lua_lock(L)	((void) 0)
#endif

#ifndef lua_unlock
#define lua_unlock(L)	((void) 0)
#endif


class LuaWrap: public luaStack
{
public:
	LuaWrap(lua_State* luaVM);
	~LuaWrap();

	LuaWrap * NewThread();

	template<typename R>
		R GetField(const char* name, const R defaultValue)
	{
		Guard  guard(this);
		
        if(get_field(name) == 1) {
        	R temp = __Lua_Wrapper_Detail__::GetValue<R>()(*this, -1);
        	lua_settop(m_pluaVM, -2);
        	return temp;
        }
 		return defaultValue;
	}

	template<typename R>
		void SetField(const char* name, R value)
	{
		Guard guard(this);
		
		Push(value);
		set_field(name);
	}
	
	class Guard
	{
	public:
		Guard(LuaWrap* wrap):m_luaWrap(wrap)
		{
			assert(m_luaWrap);
			m_luaWrap->lock();
		}
		~Guard() {
			assert(m_luaWrap);
			m_luaWrap->unlock();
		}
	private:
		LuaWrap* m_luaWrap;
	};
	
public:
	bool LoadFile(const char* filename)
	{
		return luaL_dofile(m_pluaVM, filename) == 0;
	}
	bool LoadString(const char* buffer)
	{
		return LoadBuffer(buffer, strlen(buffer));
	}
	bool LoadBuffer(const char* buffer, size_t size)
	{
		//return lua_dobuffer(m_pluaVM, buffer, size, "LuaWrap") == 0;
	}

	void Register(const char* func, lua_CFunction f)
	{
		lua_register(m_pluaVM, func, f);
	}
private:
	void lock() { lua_lock(m_pluaVM); };
	void unlock() { lua_unlock(m_pluaVM); };
	int  get_field(const char *name);
	int  set_field(const char *name);
	
	friend class Guard;

	lua_State* m_pParentLuaVM;
};

#endif

//
// End of "$Id: LuaWrap.h 1938 2006-02-20 07:54:38Z wanghw $"
//

