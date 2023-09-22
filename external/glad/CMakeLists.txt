cmake_minimum_required(VERSION 3.0.0)
project(glad)
include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/)
add_library(glad ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)
