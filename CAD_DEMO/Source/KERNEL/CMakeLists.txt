# KERNEL/CMakeLists.txt
# NOTE: This module has heavy VCL/VisIT UI dependency.
# All source files are included; additional migration work is required
# to replace VCL forms/events with their Qt equivalents.
cmake_minimum_required(VERSION 3.16)

# Only compile .cpp files directly in KERNEL/ (not Trash/ subdirectory)
file(GLOB KERNEL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude Borland package/dll entry point
list(FILTER KERNEL_SOURCES EXCLUDE REGEX "KERNEL\\.cpp$")

add_library(HouseKernel STATIC ${KERNEL_SOURCES})

target_include_directories(HouseKernel PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(HouseKernel PUBLIC
    compat_includes
    CommonAL
    MathAL
    GeomObject
    G2DObject
    BaseTool
    LuaEnv
)

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(HouseKernel PUBLIC
        Qt6::Core Qt6::Widgets Qt6::OpenGLWidgets Qt6::PrintSupport)
else()
    target_link_libraries(HouseKernel PUBLIC
        Qt5::Core Qt5::Widgets Qt5::OpenGL Qt5::PrintSupport)
endif()

# OpenGL (needed by VisIT-style rendering stubs)
find_package(OpenGL QUIET)
if(OpenGL_FOUND)
    target_link_libraries(HouseKernel PUBLIC OpenGL::GL)
endif()
