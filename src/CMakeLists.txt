add_executable(${PROJECT_NAME} shapes.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE shapes glfw)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/glfw/include/GLFW)
