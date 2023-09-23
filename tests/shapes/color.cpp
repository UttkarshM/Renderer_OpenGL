#include "color.h"
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../external/imgui/imgui.h"

namespace Shapes{
  Color::Color()
    :BackColor{0.01f,0.07f,0.05f,1.0f}
    {

    }
    Color::~Color(){

    }
    void Color::onRender(){
      glClearColor(BackColor[0],BackColor[1],BackColor[2],BackColor[3]);
      glClear(GL_COLOR_BUFFER_BIT);
    };
    void Color::imGuiRender(){
      ImGui::ColorEdit4("colors",BackColor);
    }
}
