#pragma once

#include "GLFW/glfw3.h"
#include "shapes.h"

namespace Shapes {
class Menu : public Shape {
public:
  Menu(Shape *&currentObject, GLFWwindow *window);
  ~Menu();
  template <typename T> void RegisterProp(const std::string &name) {
    std::cout << "registered the option" << name << std::endl;
    Options.push_back(std::make_pair(name, []() { return new T(); }));
  }
  void imGuiRender() override;

private:
  Shape *&currentObject;
  GLFWwindow *GLwindow;
  std::vector<std::pair<std::string, std::function<Shape *()>>> Options;
};
} // namespace Shapes
