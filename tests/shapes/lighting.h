
#include "../../external/glad/include/glad/glad.h"
#include "shapes.h"
#include"../../external/glm/glm/glm.hpp"
#include"../../external/glm/glm/gtc/matrix_transform.hpp"
#include"../../external/glm/glm/gtc/type_ptr.hpp"
#include"../../external/glm/glm/gtx/rotate_vector.hpp"
#include"../../external/glm/glm/gtx/vector_angle.hpp"
/* #include "GLFW/glfw3.h" */
#include "../../include/VAO.h"
#include "../../include/shaderClass.h"
#include "../../include/renderer.h"
#include "../../include/stb_image.h"
#include "../../include/layout.h"
#include "../../include/texture.h"
#include "camera.h"
#include <vector>
#include<memory>

namespace Shapes{
  class Lighting:public Shape{
    public:
      Lighting();
      void onRender() override;
      void imGuiRender() override;
      void Rotate();
      void Scale();
      void Traverse();
      void LightColor();
      inline std::vector<float> ReturnColor(){
        std::vector<float> vec={BackColor[0],BackColor[1],BackColor[2],BackColor[3]};
        return vec;
      };
    private:
      glm::mat4 mvp;
      float BackColor[4];
      /* glm::mat4 view; */
      /* glm::mat4 proj; */

      std::unique_ptr<VAO> vao;
      std::unique_ptr<EBO> ebo;
      std::unique_ptr<Shader> shader;
      std::unique_ptr<Renderer> renderer;
      std::unique_ptr<Texture> texture;
      std::unique_ptr<Camera> camera;
  };
}
