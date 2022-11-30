project(DigiPlaneRuntime C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(DigiPlaneRuntime ${PLATFORM})

target_sources(DigiPlaneRuntime PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
)

# link Digiplane's core to the editor
target_link_libraries(DigiPlaneRuntime DigiPlaneCore)

# copy resources to build directory
copy_resources()
