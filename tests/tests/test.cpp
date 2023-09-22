#include "test.h"

#include "../../external/imgui/imgui.h"
#include "../../external/imgui/imgui_impl_opengl3.h"
#include "../../external/imgui/imgui_impl_glfw.h"

namespace test{
  TestMenu::TestMenu(Test*& currentTestPointer)
  :current_Test(currentTestPointer)
  {
  }
  TestMenu::~TestMenu(){
    std::cout<<"deleted";
    delete(this);
  }
  void TestMenu::onImGuiRender(){
    for(auto& test : m_Tests){
      for(auto& test:m_Tests){
        if(ImGui::Button(test.first.c_str())){
          current_Test = test.second(); //this way the test gets executed and becomes the current test
        }
      }
    }
  }
}
