project(OpenGL_libs)
add_subdirectory(external/glad)
add_subdirectory(external/glfw)
add_subdirectory(external/glm)
add_subdirectory(external/imgui)


add_subdirectory(include)
add_subdirectory(tests/shapes)

add_subdirectory(src )
# target_link_libraries(${PROJECT_NAME} PUBLIC 
# tests
# )
