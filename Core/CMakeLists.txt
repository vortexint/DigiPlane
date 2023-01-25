project(DigiPlaneCore C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_library(DigiPlaneCore)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  message(STATUS "GCC detected, adding compile options")
  add_compile_options(-O3 -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  message(STATUS "MSVC detected, adding compile options")
  add_compile_options(/W4 /Ox)
endif()

target_sources(DigiPlaneCore PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/core.cpp
# ... 
)

include(graphics/CMakeLists.txt)

target_include_directories(DigiPlaneCore PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_SOURCE_DIR}/modules/DiligentCore
)

target_precompile_headers(DigiPlaneCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)

target_compile_definitions(DigiPlaneCore PRIVATE UNICODE)

target_link_libraries(DigiPlaneCore flecs_static lua_static Diligent-Common Diligent-GraphicsEngineD3D12-static)