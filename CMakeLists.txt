cmake_minimum_required(VERSION 3.0)
project(OpenGL_libs)
#include directories allows u to write <glad/glad.h> instead of the actual path
include_directories(external/glad/include)
add_subdirectory(external/glad)
include_directories(external/glfw/include)
add_subdirectory(external/glfw)
add_subdirectory(external/glm)
add_subdirectory(external/imgui)


add_subdirectory(include)
add_subdirectory(tests/shapes)
add_subdirectory(src)
# add_subdirectory(math)
# target_link_libraries(${PROJECT_NAME} PUBLIC
# tests
# )
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include/glad/)
