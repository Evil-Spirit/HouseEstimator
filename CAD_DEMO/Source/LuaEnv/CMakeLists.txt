# LuaEnv/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

file(GLOB LUAENV_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude Borland package/dll entry points
list(FILTER LUAENV_SOURCES EXCLUDE REGEX "LuaEnv\\.cpp$")
list(FILTER LUAENV_SOURCES EXCLUDE REGEX "DbgInspector\\.cpp$")

if(NOT LUAENV_SOURCES)
    message(STATUS "LuaEnv: no source files found – skipping library")
    add_library(LuaEnv INTERFACE)
    target_link_libraries(LuaEnv INTERFACE compat_includes)
    return()
endif()

add_library(LuaEnv STATIC ${LUAENV_SOURCES})

target_include_directories(LuaEnv PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${LUA_INCLUDE_DIRS}"
    # Bundled tolua headers
    "${CMAKE_CURRENT_SOURCE_DIR}/../tolua_include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../iup_include"
)

target_link_libraries(LuaEnv PUBLIC
    compat_includes
    CommonAL
    MathAL
)

if(LUA_FOUND)
    target_link_libraries(LuaEnv PUBLIC ${LUA_LIBRARIES})
else()
    target_link_libraries(LuaEnv PUBLIC lua_stub)
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(LuaEnv PUBLIC Qt6::Core Qt6::Widgets)
else()
    target_link_libraries(LuaEnv PUBLIC Qt5::Core Qt5::Widgets)
endif()
