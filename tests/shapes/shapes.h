#pragma once

/* #include "GLFW/glfw3.h" */
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace Shapes {
class Shape {
public:
  Shape(){};
  /* ~Shape(){}; */
  virtual void onRender(){};
  virtual void imGuiRender(){};
};
} // namespace Shapes
