#include "Lua.hpp"
#include "Vector3.cpp"
#include <memory>
#define LUA_VECTOR_METATABLE "LuaVectorMetaTable"

typedef Vector3<LUA_NUMBER> LuaVector;

using namespace Lua;

int lua_vector_create(lua_State* L)
{
	void* vector_ptr = lua_newuserdata(L, sizeof(LuaVector));
	new (vector_ptr) LuaVector();
	luaL_getmetatable(L, LUA_VECTOR_METATABLE);
	assert(lua_istable(L, -1));
	lua_setmetatable(L, -2);
	return 1;
}

int lua_vector_destroy(lua_State* L)
{
	LuaVector* _vector = (LuaVector*)lua_touserdata(L, -1);
	_vector->~LuaVector();
	return 0;
}

int lua_vector_add(lua_State* L)
{
	LuaVector* _vector1 = (LuaVector*)lua_touserdata(L, -2);
	LuaVector* _vector2 = (LuaVector*)lua_touserdata(L, -1);

	return 0;
}

int luaopen_libvector(lua_State* L)
{
	static const struct luaL_Reg nativeFuncLib[] =
	{
		{"mult50", l_mult50}, // Your function name, and the function reference after
		{NULL, NULL} 
	};

	lua_register(L, "nativelib", nativeFuncLib);
	return 1;
}