# GeomObject/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

file(GLOB GEOM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude the Borland package/dll entry point if present
list(FILTER GEOM_SOURCES EXCLUDE REGEX "GeomObject\\.cpp$")

add_library(GeomObject STATIC ${GEOM_SOURCES})

target_include_directories(GeomObject PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(GeomObject PUBLIC
    compat_includes
    CommonAL
    MathAL
)

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(GeomObject PUBLIC Qt6::Core)
else()
    target_link_libraries(GeomObject PUBLIC Qt5::Core)
endif()
