#define GLFW_INCLUDE_NONE

#include "../external/glad/include/glad/glad.h"
#include "../external/glfw/include/GLFW/glfw3.h"
/* #include "glad/glad.h" */
/* #include "GLFW/glfw3.h" */

/* #include "../include/VAO.h" */
/* #include "../include/renderer.h" */
/* #include "../include/shaderClass.h" */

#include "../external/imgui/imgui.h"
#include "../external/imgui/imgui_impl_glfw.h"
#include "../external/imgui/imgui_impl_opengl3.h"

#include "../tests/shapes/color.h"
#include "../tests/shapes/menu.h"
#include "../tests/shapes/shapes.h"
#include "../tests/shapes/triangles.h"

int main() {
  const char *glsl_version = "#version 130";
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight,
                                        "this is a window", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  gladLoadGL();
  std::cout<<"first cycle"<<&window<<std::endl;

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags = ImGuiConfigFlags_NavEnableGamepad;
  io.ConfigFlags = ImGuiConfigFlags_NavEnableKeyboard;

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);
  glViewport(0, 0, windowWidth, windowHeight);
  {
    ImGui::StyleColorsDark();
    bool show_demo_window = true;

    Shapes::Color color;
    Shapes::Shape *current = nullptr;
    Shapes::Menu *menu = new Shapes::Menu(current);
    current = menu;
    current->GLwindow=window;

    menu->RegisterProp<Shapes::Color>("set color");
    menu->RegisterProp<Shapes::Triangle>("create a triangle");
    menu->RegisterProp<Shapes::Lighting>("create the lighting");

    while (!glfwWindowShouldClose(window)) {
      glfwPollEvents();
      color.onRender();
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();
      if (current) {
        current->onRender();
        ImGui::ShowDemoWindow(&show_demo_window);
        ImGui::Begin("window");
        if (current != menu && ImGui::Button("<-")) {
          delete current;
          current = menu;
        }
        current->imGuiRender();
        ImGui::End();
      }
      ImGui::Render();
      int displayw, displayh;
      glfwGetFramebufferSize(window, &displayw, &displayh);
      glViewport(0, 0, displayw, displayh);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
      glfwSwapBuffers(window);
    }
    delete current;
  }
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
