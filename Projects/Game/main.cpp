// cmake
// lua api
// glut
// sfml

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lua.hpp"



using namespace Lua;

int main(int argc, char *argv[])
{
    
    char *path = nullptr;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--path") == 0 && i + 1 < argc)
        {
            i++;
            path = argv[i];
        }
    }
    if (path == nullptr)
        path = "script.lua";
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);

    int r = luaL_dofile(state, path);
    if (r == LUA_OK)
    {
        lua_getglobal(state, "a");
        lua_getglobal(state, "b");
        if (lua_isnumber(state, -1))
            std::cout << "b = " << (int)lua_tointeger(state, -1) << std::endl;
        lua_remove(state, -1);
        if (lua_isnumber(state, -1))
            std::cout << "a = " << (int)lua_tointeger(state, -1) << std::endl;
    }
    else
    {

        std::cout << "error!\n";
        if (lua_isstring(state, -1))
            std::cout << lua_tostring(state, -1) << std::endl;
    }

    lua_close(state);
    return 0;
}