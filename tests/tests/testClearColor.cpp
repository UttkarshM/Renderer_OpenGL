#include "testClearColor.h"
#include "test.h"
#include <glad/glad.h>
#include "../../external/imgui/imgui.h"
#include "../../external/imgui/imgui_impl_opengl3.h"
#include "../../external/imgui/imgui_impl_glfw.h"


namespace test{
  TestClearColor::TestClearColor()
  :m_ClearColor {0.2f,0.3f,0.4f,1.0f}
  {
  }
  TestClearColor::~TestClearColor()
  {
  }
  void TestClearColor::onUpdate(float deltaTime)
  {
  }
  void TestClearColor::onRender()
  {
    glClearColor(m_ClearColor[0],m_ClearColor[1],m_ClearColor[2],m_ClearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
  }
  void TestClearColor::onImGuiRender()
  {
    ImGui::ColorEdit4("colors",m_ClearColor);
  }
}
