project(DigiPlaneRuntime C CXX)

add_executable(DigiPlaneRuntime)
set_target_properties(DigiPlaneEditor PROPERTIES OUTPUT_NAME "Runtime")

target_sources(DigiPlaneRuntime PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
)

# link Digiplane's core to the editor
target_link_libraries(DigiPlaneRuntime DigiPlaneCore)