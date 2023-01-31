project(DigiPlaneCore C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_library(DigiPlaneCore)

target_sources(DigiPlaneCore PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/core.cpp
${CMAKE_CURRENT_SOURCE_DIR}/plugins/nuklear_impl.cpp
# ... 
)

include(graphics/CMakeLists.txt)

target_include_directories(DigiPlaneCore PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_SOURCE_DIR}/modules/DiligentCore
)

target_precompile_headers(DigiPlaneCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)

target_compile_definitions(DigiPlaneCore PRIVATE UNICODE)

target_link_libraries(DigiPlaneCore flecs_static lua_static glfw Diligent-Common Diligent-GraphicsEngineD3D12-static)