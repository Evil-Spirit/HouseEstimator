# G2DObject/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

file(GLOB G2D_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude Borland package entry point
list(FILTER G2D_SOURCES EXCLUDE REGEX "G2DObject\\.cpp$")

if(NOT G2D_SOURCES)
    message(STATUS "G2DObject: no source files found – skipping library")
    # Create an empty interface target so dependants can still link
    add_library(G2DObject INTERFACE)
    target_link_libraries(G2DObject INTERFACE compat_includes)
else()
    add_library(G2DObject STATIC ${G2D_SOURCES})

    target_include_directories(G2DObject PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
    )

    target_link_libraries(G2DObject PUBLIC
        compat_includes
        CommonAL
        MathAL
    )

    if(QT_VERSION_MAJOR EQUAL 6)
        target_link_libraries(G2DObject PUBLIC Qt6::Core)
    else()
        target_link_libraries(G2DObject PUBLIC Qt5::Core)
    endif()
endif()
