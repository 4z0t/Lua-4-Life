
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(emlua)

# option(USE_STATIC "Use static libtrary" ON)
if(MSVC)
    set(LUA_LIB "${PROJECT_SOURCE_DIR}/../../Lua/lua-5.4.2_Win64/")
elseif(WIN32)
    set(LUA_LIB "${PROJECT_SOURCE_DIR}/../../Lua/lua-5.4.2_Win32/")
endif()

add_executable(emlua

    main.cpp

    ${LUA_LIB}/include/lua.h
    ${LUA_LIB}/include/lualib.h
    ${LUA_LIB}/include/lauxlib.h
)
message("linking ${LUA_LIB}")
target_link_libraries(emlua ${LUA_LIB}/liblua54.a)

set(LUA_DLL_NAME "lua54.dll")
set(LUA_DLL "${LUA_LIB}/${LUA_DLL_NAME}")


file(COPY ${LUA_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})