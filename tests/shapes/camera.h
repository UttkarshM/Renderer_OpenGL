#pragma once

#include "../../external/glad/include/glad/glad.h"
#include "../../external/glfw/include/GLFW/glfw3.h"
#include "../../external/glm/glm/glm.hpp"
#include "../../external/glm/glm/gtc/matrix_transform.hpp"
#include "../../external/glm/glm/gtc/type_ptr.hpp"
#include "../../external/glm/glm/gtx/rotate_vector.hpp"
#include "../../external/glm/glm/gtx/vector_angle.hpp"

#include "../../include/shaderClass.h"

#include "../../external/imgui/imgui.h"
#include "../../external/imgui/imgui_impl_glfw.h"
#include "../../external/imgui/imgui_impl_opengl3.h"

class Camera {
public:
  Camera(GLfloat defaultVal = 0.0f);
  glm::mat4 Translate();
  glm::mat4 Rotate();
  glm::mat4 Scale();
  glm::mat4 MATRIX();

private:
  glm::mat4 translate;
  glm::mat4 rotate;
  glm::mat4 scaler;
  float xRotate;
  float yRotate;
  float zRotate;
  glm::vec3 matrix;
  glm::vec3 translateVec;

  bool local;
};
