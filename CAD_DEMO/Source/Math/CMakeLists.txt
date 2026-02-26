# Math/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

file(GLOB MATH_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude Borland package entry points (.bpk companion files generate these)
list(FILTER MATH_SOURCES EXCLUDE REGEX "MathAL\\.cpp$")

add_library(MathAL STATIC
    VectorV.cpp
    MathV.cpp
    MatrixV.cpp
    MathAL.cpp
)

target_include_directories(MathAL PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(MathAL PUBLIC
    compat_includes
)

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(MathAL PUBLIC Qt6::Core)
else()
    target_link_libraries(MathAL PUBLIC Qt5::Core)
endif()
