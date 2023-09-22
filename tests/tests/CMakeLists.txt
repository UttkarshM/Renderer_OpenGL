#TODO  solve this by configuring this 
#TODO learn cmake properly lmaoooo

cmake_minimum_required(VERSION 3.0.0)
add_library(tests 
  testClearColor.cpp
  test.cpp
  testTexture.cpp)

# include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/include/resources/shaders)
# include_directories(${PROJECT_NAME}  ${CMAKE_SOURCE_DIR}/external/imgui)
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(
  tests
  PUBLIC
  includes
  glm
  glad
  glfw
  imgui 
)
