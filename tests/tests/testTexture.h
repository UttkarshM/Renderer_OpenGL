#pragma once

#include "test.h"
/* #include "../../include/EBO.h" */
/* #include "../../include/VBO.h" */
#include "../../include/VAO.h"
#include "../../include/shaderClass.h"
#include "../../include/layout.h"
#include "../../include/texture.h"
#include "../../external/glm/glm/glm.hpp"
#include "../../external/glm/glm/gtc/matrix_transform.hpp"
#include "../../include/stb_image.h"
#include "../../include/renderer.h"
#include "../../include/texture.h"
#include <memory>

namespace test{
  class TestTexture: public Test{
    public:
      TestTexture();
      ~TestTexture();
      void onUpdate(float deltaTime) override;
      void onRender() override;
      void onImGuiRender() override;
    private:
      std::unique_ptr<VAO> vao;
      std::unique_ptr<EBO> ebo;
      std::unique_ptr<Shader> Program;
      std::unique_ptr<Texture> texturer;
      glm::vec3 translationA;
      glm::vec3 translationB;
      
  };
}
