# MAIN/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

# Collect all .cpp files in MAIN/ except the old Borland WinMain entry point
file(GLOB MAIN_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# pConfig.cpp contains Borland's WinMain – exclude it; we provide main_qt.cpp
list(FILTER MAIN_SOURCES EXCLUDE REGEX "pConfig\\.cpp$")
# Also exclude WebVer.cpp if it only contains Borland version resource
# (keep it – it may have useful code; the migration script will sanitize it)

# Add the new Qt entry point and main window implementation
list(APPEND MAIN_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/main_qt.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/HouseEstimatorWindow.cpp"
)

add_executable(HouseEstimator WIN32 ${MAIN_SOURCES})

target_include_directories(HouseEstimator PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(HouseEstimator PRIVATE
    compat_includes
    HouseKernel
    CommonAL
    MathAL
    GeomObject
    G2DObject
    BaseTool
    LuaEnv
)

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(HouseEstimator PRIVATE
        Qt6::Core Qt6::Widgets Qt6::OpenGLWidgets Qt6::PrintSupport)
else()
    target_link_libraries(HouseEstimator PRIVATE
        Qt5::Core Qt5::Widgets Qt5::OpenGL Qt5::PrintSupport)
endif()

# On Windows, also link against the platform entry-point helper
if(WIN32)
    set_target_properties(HouseEstimator PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()
