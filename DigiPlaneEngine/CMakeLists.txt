project(DigiPlaneEditor C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_library(DigiPlaneEngine STATIC)

target_sources(DigiPlaneEngine PUBLIC
${CMAKE_CURRENT_LIST_DIR}/glad.c
${CMAKE_CURRENT_LIST_DIR}/all_include.hpp
${CMAKE_CURRENT_LIST_DIR}/Engine.hpp
${CMAKE_CURRENT_LIST_DIR}/Engine.cpp
)

target_include_directories(DigiPlaneEngine PUBLIC
${CMAKE_SOURCE_DIR}/include
${CMAKE_CURRENT_LIST_DIR}/include
)

# link SDL2 statically
target_link_libraries(DigiPlaneEngine PUBLIC SDL2-static SDL2main opengl32)