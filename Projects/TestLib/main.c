#ifdef _WIN64
#include "../../Lua/lua-5.4.2_Win64/include/lua.h"
#include "../../Lua/lua-5.4.2_Win64/include/lauxlib.h"
#elif _WIN32
#include "../../Lua/lua-5.4.2_Win32/include/lua.h"
#include "../../Lua/lua-5.4.2_Win32/include/lauxlib.h"
#endif


static int lua_test_func(lua_State* L)
{
	lua_Number a = luaL_checknumber(L, -1);
	lua_pushnumber(L, a * a);
	return 1;
}

int luaopen_libtest(lua_State* L)
{
	static const struct luaL_Reg nativeFuncLib[] =
	{
		{"test", lua_test_func},
		{NULL, NULL}
	};

	luaL_setfuncs(L, nativeFuncLib, 0);
	lua_pushvalue(L, -1);
	lua_setglobal(L, "testlib");
	return 1;
}