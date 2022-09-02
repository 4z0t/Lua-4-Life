
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(game)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
set(WIN64 true)
    # 64 bits
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    # 32 bits
endif()

add_executable(game

    main.cpp

)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)


include(FindLua)
find_package(Lua REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME}  ${LUA_LIBRARIES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${LUA_INCLUDE_DIR})

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME}  glfw)



find_package(glbinding CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME}  glbinding::glbinding)

find_package(GLEW REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME}   GLEW::GLEW)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME}  glm)


set(LUA_SCRIPT_NAME "script.lua")
file(COPY ${LUA_SCRIPT_NAME} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})