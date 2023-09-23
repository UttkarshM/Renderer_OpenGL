add_library(shapes
  STATIC
  color.cpp
  menu.cpp
  triangles.cpp
)
target_include_directories(shapes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(shapes PUBLIC includes glm glad glfw imgui)
