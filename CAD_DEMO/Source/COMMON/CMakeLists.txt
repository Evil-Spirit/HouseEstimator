# COMMON/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

# Collect all .cpp files – form-based ones will be compiled using Qt widget stubs
file(GLOB COMMON_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Exclude the Borland package entry point (DllEntryPoint / USEFORM list)
list(FILTER COMMON_SOURCES EXCLUDE REGEX "CommonAL\\.cpp$")

add_library(CommonAL STATIC ${COMMON_SOURCES})

target_include_directories(CommonAL PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(CommonAL PUBLIC
    compat_includes
    MathAL
)

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(CommonAL PUBLIC Qt6::Core Qt6::Widgets)
else()
    target_link_libraries(CommonAL PUBLIC Qt5::Core Qt5::Widgets)
endif()

# Export symbol for shared build (COMMONAL_EXPORTS enables dllexport)
target_compile_definitions(CommonAL PRIVATE COMMONAL_EXPORTS)
