#pragma once
#include "shapes.h"

#include "../../external/glm/glm/glm.hpp"
#include "../../external/glm/glm/gtc/matrix_transform.hpp"

#include "../../external/imgui/imgui.h"
#include "../../external/imgui/imgui_impl_glfw.h"
#include "../../external/imgui/imgui_impl_opengl3.h"

#include "../../include/VAO.h"
#include "../../include/shaderClass.h"
#include "../../include/renderer.h"
#include "../../include/stb_image.h"
#include "../../include/layout.h"

#include <algorithm>
#include <memory>

#define windowWidth 960
#define windowHeight 540


namespace Shapes{
  class Triangle:public Shape{
    public:
      Triangle();
      ~Triangle();
      void onRender() override;
      void imGuiRender() override;
    private:
      glm::vec3 translation;
      /* glm::mat4 view; */
      /* glm::mat4 proj; */

      std::unique_ptr<VAO> vao;
      std::unique_ptr<EBO> ebo;
      std::unique_ptr<Shader> shader;
      std::unique_ptr<Renderer> renderer;
  };

}
