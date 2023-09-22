#include "testTextBox.h"
#include "test.h"
#include <glad/glad.h>
#include <string>
#include "../../external/imgui/imgui.h"
#include "../../external/imgui/imgui_impl_opengl3.h"
#include "../../external/imgui/imgui_impl_glfw.h"

namespace test{
  TextBox::TextBox()
  :stre("")
  {
    char buffer[256];
    ImGui::InputText("",&buffer[0],sizeof(buffer));
    stre=buffer;
  }
  void TextBox::onImGuiRender(){
    ImGui::Text("%s",stre.c_str());
  }
}

