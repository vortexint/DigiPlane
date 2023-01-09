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
${CMAKE_CURRENT_SOURCE_DIR}/core.cpp
# ... 
)

include(graphics/CMakeLists.txt)

target_include_directories(DigiPlaneCore PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_SOURCE_DIR}/${DILIGENT_CORE_DIR}
)

target_precompile_headers(DigiPlaneCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)

target_compile_definitions(DigiPlaneCore PRIVATE UNICODE ENGINE_DLL=0)

target_link_libraries(DigiPlaneCore flecs_static lua_static glfw
                      Diligent-Common
                      Diligent-GraphicsTools
                      Diligent-RenderStateNotation
                      Diligent-GraphicsEngineD3D11-static
                      Diligent-GraphicsEngineD3D12-static
                      Diligent-GraphicsEngineVk-static)