
#project(glad)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(glad ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)
