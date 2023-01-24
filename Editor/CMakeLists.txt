project(DigiPlaneEditor C CXX)

add_executable(DigiPlaneEditor)
set_target_properties(DigiPlaneEditor PROPERTIES OUTPUT_NAME "Editor")

target_sources(DigiPlaneEditor PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.rc
)

# link Digiplane's core to the editor
target_link_libraries(DigiPlaneEditor DigiPlaneCore)

# copy contents of resources to binary directory
add_custom_command(TARGET DigiPlaneEditor POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_CURRENT_LIST_DIR}/resources $<TARGET_FILE_DIR:DigiPlaneEditor>
)