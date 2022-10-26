project(DigiPlaneEditor C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(DigiPlaneEditor WIN32)

target_sources(DigiPlaneEditor PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.rc
)

target_include_directories(DigiPlaneEditor PRIVATE
${CMAKE_SOURCE_DIR}/include
${CMAKE_SOURCE_DIR}/DigiPlaneEngine
)

# link SDL2 statically
target_link_libraries(DigiPlaneEditor PUBLIC DigiPlaneEngine)

# copy resources to build directory
copy_resources()
