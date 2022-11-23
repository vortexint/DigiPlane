project(DigiPlaneCore C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_library(DigiPlaneCore)

if(MSVC)
  target_compile_options(DigiPlaneCore PRIVATE /W4)
else()
  target_compile_options(DigiPlaneCore PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_sources(DigiPlaneCore PRIVATE
${CMAKE_CURRENT_LIST_DIR}/core.cpp
)

target_include_directories(DigiPlaneCore PRIVATE
${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(DigiPlaneCore bgfx flecs_static)

# copy resources to build directory
copy_resources()
