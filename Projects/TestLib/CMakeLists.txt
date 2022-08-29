
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(testlib)

# option(USE_STATIC "Use static libtrary" ON)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
set(WIN64 true)
    # 64 bits
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    # 32 bits
endif()


if(WIN64)
message(STATUS "64 bit build")
    set(LUA_LIB "${PROJECT_SOURCE_DIR}/../../Lua/lua-5.4.2_Win64/")
elseif(WIN32)
message(STATUS "32 bit build")
    set(LUA_LIB "${PROJECT_SOURCE_DIR}/../../Lua/lua-5.4.2_Win32/")
endif()

add_library(testlib SHARED

    "main.c"
    ${LUA_LIB}/include/lua.h
    ${LUA_LIB}/include/lauxlib.h
    )
message("linking ${LUA_LIB}")
target_link_libraries(testlib PUBLIC ${LUA_LIB}/liblua54.a)

set(LUA_DLL_NAME "lua54.dll")
set(LUA_DLL "${LUA_LIB}/${LUA_DLL_NAME}")


file(COPY ${LUA_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})