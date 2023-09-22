# add_library(stb_image stb_image.cpp)

add_library(includes
  STATIC
  VAO.cpp
  VBO.cpp
  EBO.cpp
  shaderClass.cpp
  texture.cpp
  renderer.cpp)
include_directories(resources)
# target_include_directories(
#   includes 
#   PUBLIC 
#   ${CMAKE_CURRENT_LIST_DIR}
#   )

target_include_directories(includes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# include_directories(build)

