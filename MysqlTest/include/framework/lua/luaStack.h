//  "$Id: luaStack.h 1883 2006-02-13 03:02:27Z wanghw $"
//   (c) Copyright 1992-2005, ZheJiang Dahua Information Technology Stock CO.LTD.
//                            All Rights Reserved
//
//	文 件 名： luaStack.h
//	描    述:  LUA引擎的封装
//	修改记录： 2005-8-22 Peter Wang <wanghw@dhmail.com> Initial Version
//

#ifndef __lua_stack_h__
#define __lua_stack_h__

#include <string>

extern "C"
{
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
};


class luaStack;

namespace __Lua_Wrapper_Detail__ {
	template<typename R>
	struct GetValue
	{
		R operator()(luaStack& l, int index)
		{
			// !!! ERROR !!!
			return ;
		}
	};
};

	
class luaStack
{
public:
	luaStack(lua_State* luaVM)
		: m_pluaVM(luaVM)
	{
	}
public:
	bool operator !()
	{
		return m_pluaVM == NULL;
	}
	operator bool()
	{
		return m_pluaVM != NULL;
	}
	operator lua_State* ()
	{
		return m_pluaVM;
	}

public:
	inline void Push()
	{
		lua_pushnil(m_pluaVM);
	}
	inline void Push(const char* param)
	{
		lua_pushstring(m_pluaVM, param);
	}
	inline void Push(const std::string& param)
	{
		lua_pushlstring(m_pluaVM, param.c_str(), param.size());
	}
	inline void Push(int param)
	{
		lua_pushnumber(m_pluaVM, param);
	}
	inline void Push(double param)
	{
		lua_pushnumber(m_pluaVM, param);
	}
	inline void Push(bool param)
	{
		lua_pushboolean(m_pluaVM, param);
	}
	inline void Push(lua_CFunction  param)
	{
		lua_pushcfunction(m_pluaVM, param);
	}

public:
	template<typename R>
	inline R Pop(int count = 1)
	{
		R temp = getValue<R>(-count);
		lua_settop(m_pluaVM, (-count)-1);
		return temp;
	}
	inline void Pop(int count = 1)
	{
		lua_settop(m_pluaVM, (-count)-1);
	}
public:
	int GetParamCount()
	{
		return lua_gettop(m_pluaVM);
	}

	template<typename R>
		R GetParam(int id)
	{
		int nTop = GetParamCount();
		LuaAssert(id != 0 && id <= nTop && id >= -nTop, id, "Not enough parameters");
		return getValue<R>(id);
	}

	inline void LuaAssert(bool condition, int argindex, const char* err_msg) 
	{
		luaL_argcheck(m_pluaVM, condition, argindex, err_msg);
	}

	inline void LuaAssert(bool condition, const char* err_msg)
	{
		if(!condition)
		{
			lua_Debug ar;
			lua_getstack(m_pluaVM, 0, &ar);
			lua_getinfo(m_pluaVM, "n", &ar);
			if (ar.name == NULL)
				ar.name = "?";
			luaL_error(m_pluaVM, "assert fail: %s `%s' (%s)", ar.namewhat, ar.name, err_msg);
		}
	}

	template<typename R>
		R GetGlobal(const char* name)
	{
		lua_getglobal(m_pluaVM, name);  
		return Pop<R>();
	}

	template<typename R>
		void SetGlobal(const char* name, R value)
	{
		Push(value);
		lua_setglobal(m_pluaVM, name);
	}

private:
	template<typename R>
	inline R getValue(int index = -1)
	{
		return __Lua_Wrapper_Detail__::GetValue<R>()(*this, index);
	}

private:
	inline void beginCall(const char* func)
	{
		lua_getglobal(m_pluaVM, func);  
	}

	template<typename R>
		R endCall(int nArg)
	{
		if(lua_pcall(m_pluaVM, nArg, 1, 0) != 0)
		{
			Pop(); // Pop error message
			return 0;
		}

		return Pop<R>();
	}

	template< int n >
		void endCall(int nArg)
	{
		if(lua_pcall(m_pluaVM, nArg, 0, 0) != 0)
			Pop(); // Pop error message
	}
public:
	// Call Lua function
	//   func:	Lua function name
	//   R:		Return type. (void, float, double, int, long, bool, const char*, std::string)
	// Sample:	double f = lua.Call<double>("test0", 1.0, 3, "param");
	template<typename R>
		R Call(const char* func)
	{
		beginCall(func);
		return endCall<R>(0);
	}

	template<typename R, typename P1>
		R Call(const char* func, P1 p1)
	{
		beginCall(func);
		Push(p1);
		return endCall<R>(1);
	}

	template<typename R, typename P1, typename P2>
		R Call(const char* func, P1 p1, P2 p2)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		return endCall<R>(2);
	}

	template<typename R, typename P1, typename P2, typename P3>
		R Call(const char* func, P1 p1, P2 p2, P3 p3)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		return endCall<R>(3);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		return endCall<R>(4);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		Push(p5);
		return endCall<R>(5);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		Push(p5);
		Push(p6);
		return endCall<R>(6);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		Push(p5);
		Push(p6);
		Push(p7);
		return endCall<R>(7);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		Push(p5);
		Push(p6);
		Push(p7);
		Push(p8);
		return endCall<R>(8);
	}


	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		Push(p5);
		Push(p6);
		Push(p7);
		Push(p8);
		Push(p9);
		return endCall<R>(9);
	}



	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
		R Call(const char* func, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
	{
		beginCall(func);
		Push(p1);
		Push(p2);
		Push(p3);
		Push(p4);
		Push(p5);
		Push(p6);
		Push(p7);
		Push(p8);
		Push(p9);
		Push(p10);
		return endCall<R>(10);
	}
	
protected:
	lua_State* m_pluaVM;
};


namespace __Lua_Wrapper_Detail__ {
	template<>
	struct GetValue<float>
	{
		float operator()(luaStack& l, int index)
		{
			return static_cast<float>(lua_tonumber((lua_State*)l, index));
		}
	};


	template<>
	struct GetValue<double>
	{
		double operator()(luaStack& l, int index)
		{
			return lua_tonumber((lua_State*)l, index);
		}
	};

	template<>
	struct GetValue<long double>
	{
		long double operator()(luaStack& l, int index)
		{
			return lua_tonumber((lua_State*)l, index);
		}
	};

	template<>
	struct GetValue<int>
	{
		int operator()(luaStack& l, int index)
		{
			return static_cast<int>(lua_tonumber((lua_State*)l, index));
		}
	};

	template<>
	struct GetValue<long>
	{
		long operator()(luaStack& l, int index)
		{
			return static_cast<long>(lua_tonumber((lua_State*)l, index));
		}
	};

	template<>
	struct GetValue<const char*>
	{
		const char* operator()(luaStack& l, int index)
		{
			return lua_tostring((lua_State*)l, index);
		}
	};

	template<>
	struct GetValue<std::string>
	{
		std::string operator()(luaStack& l, int index)
		{
			return std::string(lua_tostring((lua_State*)l, index), lua_strlen((lua_State*)l, index));
		}
	};

	template<>
	struct GetValue<bool>
	{
		bool operator()(luaStack& l, int index)
		{
			return lua_toboolean((lua_State*)l, index) != 0;
		}
	};
};  // namespace __Lua_Wrapper_Detail__ 

#endif

//
// End of "$Id: luaStack.h 1883 2006-02-13 03:02:27Z wanghw $"
//

