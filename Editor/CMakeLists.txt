project(DigiPlaneEditor C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(DigiPlaneEditor WIN32)

if(MSVC)
  target_compile_options(DigiPlaneEditor PRIVATE /W4)
else()
  target_compile_options(DigiPlaneEditor PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_sources(DigiPlaneEditor PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.rc
)

target_include_directories(DigiPlaneEditor PRIVATE
${CMAKE_SOURCE_DIR}/include
)

# link SDL2 and flecs
target_link_libraries(DigiPlaneEditor PUBLIC SDL2-static SDL2main opengl32 flecs_static)

# copy resources to build directory
copy_resources()
