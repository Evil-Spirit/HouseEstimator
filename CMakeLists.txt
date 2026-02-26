cmake_minimum_required(VERSION 3.16)
project(HouseEstimator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Help AUTOUIC locate the generated .ui files (from DFM→UI conversion).
# Each module subdirectory contains .ui files alongside the source files.
set(CMAKE_AUTOUIC_SEARCH_PATHS
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/MAIN"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/KERNEL"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/COMMON"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/LuaEnv"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/GridEdit"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/ObjectInspector"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/Sample"
    "${CMAKE_SOURCE_DIR}/CAD_DEMO/Source/TestObj"
)

# ---------------------------------------------------------------------------
# Qt discovery – prefer Qt6, fall back to Qt5
# ---------------------------------------------------------------------------
find_package(Qt6 COMPONENTS Core Widgets OpenGLWidgets PrintSupport QUIET)
if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
    message(STATUS "Using Qt6 ${Qt6_VERSION}")
else()
    find_package(Qt5 5.15 COMPONENTS Core Widgets OpenGL PrintSupport REQUIRED)
    set(QT_VERSION_MAJOR 5)
    message(STATUS "Using Qt5 ${Qt5_VERSION}")
endif()

# ---------------------------------------------------------------------------
# Global compiler settings
# ---------------------------------------------------------------------------
if(MSVC)
    add_compile_options(/W3 /wd4100 /wd4996 /wd4251)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS NOMINMAX)
else()
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-deprecated-declarations)
endif()

add_subdirectory(CAD_DEMO)
