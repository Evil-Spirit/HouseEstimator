# BaseTool/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

file(GLOB BASETOOL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude Borland package entry point
list(FILTER BASETOOL_SOURCES EXCLUDE REGEX "BaseTool\\.cpp$")

if(NOT BASETOOL_SOURCES)
    message(STATUS "BaseTool: no source files found – skipping library")
    add_library(BaseTool INTERFACE)
    target_link_libraries(BaseTool INTERFACE compat_includes)
else()
    add_library(BaseTool STATIC ${BASETOOL_SOURCES})

    target_include_directories(BaseTool PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
    )

    target_link_libraries(BaseTool PUBLIC
        compat_includes
        MathAL
    )

    if(QT_VERSION_MAJOR EQUAL 6)
        target_link_libraries(BaseTool PUBLIC Qt6::Core Qt6::Widgets)
    else()
        target_link_libraries(BaseTool PUBLIC Qt5::Core Qt5::Widgets)
    endif()
endif()
