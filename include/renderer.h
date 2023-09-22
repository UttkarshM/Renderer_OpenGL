#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "EBO.h"
#include "VAO.h"
#include "shaderClass.h"


class Renderer{
  public:
    void Draw(VAO& vao,EBO& ebo,Shader& shader);
    void ClearBuffer();
};
