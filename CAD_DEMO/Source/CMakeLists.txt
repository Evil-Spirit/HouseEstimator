# CAD_DEMO/Source/CMakeLists.txt
# Orchestrator: sets up global compat include path and adds all module subdirs.

cmake_minimum_required(VERSION 3.16)

# ---------------------------------------------------------------------------
# Compat directory (system include so its headers shadow any project headers
# with the same name, e.g., VisClass.hpp stubs shadow the real VisIT headers).
# ---------------------------------------------------------------------------
set(COMPAT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/compat")

# A INTERFACE library that propagates the compat include path to all consumers.
add_library(compat_includes INTERFACE)
target_include_directories(compat_includes SYSTEM INTERFACE
    "${COMPAT_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# All modules using the compat layer need Qt Core + Widgets (vcl_qt.h includes Qt Widgets)
if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(compat_includes INTERFACE Qt6::Core Qt6::Widgets Qt6::PrintSupport)
else()
    target_link_libraries(compat_includes INTERFACE Qt5::Core Qt5::Widgets Qt5::PrintSupport)
endif()

# ---------------------------------------------------------------------------
# Lua – optional, needed by LuaEnv
# ---------------------------------------------------------------------------
find_package(PkgConfig QUIET)
set(LUA_FOUND_BY "" CACHE INTERNAL "")

if(PKG_CONFIG_FOUND)
    pkg_check_modules(LUA QUIET lua5.4)
    if(NOT LUA_FOUND)
        pkg_check_modules(LUA QUIET lua5.3)
    endif()
    if(NOT LUA_FOUND)
        pkg_check_modules(LUA QUIET lua5.2)
    endif()
    if(NOT LUA_FOUND)
        pkg_check_modules(LUA QUIET lua5.1)
    endif()
    if(NOT LUA_FOUND)
        pkg_check_modules(LUA QUIET lua)
    endif()
    if(LUA_FOUND)
        set(LUA_FOUND_BY "pkg-config" CACHE INTERNAL "")
    endif()
endif()

if(NOT LUA_FOUND)
    find_package(Lua QUIET)
    if(LUA_FOUND)
        set(LUA_FOUND_BY "find_package" CACHE INTERNAL "")
        set(LUA_INCLUDE_DIRS "${LUA_INCLUDE_DIR}")
        set(LUA_LIBRARIES    "${LUA_LIBRARIES}")
    endif()
endif()

# Always add the bundled lua_include as a fallback
list(APPEND LUA_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/lua_include")

if(LUA_FOUND)
    message(STATUS "Lua found via ${LUA_FOUND_BY}: ${LUA_LIBRARIES}")
else()
    message(STATUS "System Lua not found – using bundled lua_include headers only")
    # Create a dummy INTERFACE target so CMake targets can still link against it
    add_library(lua_stub INTERFACE)
    target_include_directories(lua_stub INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lua_include")
    set(LUA_LIBRARIES lua_stub)
    set(LUA_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/lua_include")
endif()

# Export for child CMakeLists
set(LUA_INCLUDE_DIRS "${LUA_INCLUDE_DIRS}" CACHE INTERNAL "")
set(LUA_LIBRARIES    "${LUA_LIBRARIES}"    CACHE INTERNAL "")

# ---------------------------------------------------------------------------
# Module subdirectories (order matters – dependencies first)
# ---------------------------------------------------------------------------
add_subdirectory(Math)
add_subdirectory(COMMON)
add_subdirectory(GeomObject)
add_subdirectory(G2DObject)
add_subdirectory(BaseTool)
add_subdirectory(LuaEnv)
add_subdirectory(KERNEL)
add_subdirectory(MAIN)
