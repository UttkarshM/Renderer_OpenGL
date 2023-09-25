#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"../../external/glm/glm/glm.hpp"
#include"../../external/glm/glm/gtc/matrix_transform.hpp"
#include"../../external/glm/glm/gtc/type_ptr.hpp"
#include"../../external/glm/glm/gtx/rotate_vector.hpp"
#include"../../external/glm/glm/gtx/vector_angle.hpp"

#include "../../include/shaderClass.h"


class Camera
{
  public:
    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0.0f,0.0f,-1.0f);
    glm::vec3 Up = glm::vec3(0.0f,1.0f,0.0f);

    int width,height;

    float speed=0.1f,sensitivity=100.0f;

    Camera(int width,int height,glm::vec3 position);
    void Matrix(float FOVdeg,float nearplane,float farplane,Shader& shader,const char* uniform);
    void Inputs(GLFWwindow* window);
};






