#include "menu.h"
#include "../../external/imgui/imgui.h"
/* #include "../../external/imgui/imgui_impl_glfw.h" */
/* #include "../../external/imgui/imgui_impl_opengl3.h" */
#include "shapes.h"
namespace Shapes {
Menu::Menu(Shape *&currentTest)
    : currentObject(currentTest) {std::cout<<&this->GLwindow;}
Menu::~Menu() {
  std::cout << "deleted";
  delete (this);
}
void Menu::imGuiRender() {
  for (auto option : Options) {
    if (ImGui::Button(option.first.c_str())) {
      currentObject = option.second();
    }
  }
}
} // namespace Shapes
