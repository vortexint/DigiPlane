project(DigiPlaneEditor C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)

add_library(DigiPlaneEngine STATIC)

if(MSVC)
  target_compile_options(DigiPlaneEngine PRIVATE /W4)
else()
  target_compile_options(DigiPlaneEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_sources(DigiPlaneEngine PRIVATE
${CMAKE_CURRENT_LIST_DIR}/glad.c
${CMAKE_CURRENT_LIST_DIR}/Scene.cpp
${CMAKE_CURRENT_LIST_DIR}/Engine.cpp
${CMAKE_CURRENT_LIST_DIR}/Utils.cpp
)

target_include_directories(DigiPlaneEngine PUBLIC
${CMAKE_SOURCE_DIR}/include
${CMAKE_CURRENT_LIST_DIR}/include

)

# link SDL2 and flecs
target_link_libraries(DigiPlaneEngine PUBLIC SDL2-static SDL2main opengl32 flecs_static)