#include "triangles.h"
#include <memory>
#include <vector>

namespace Shapes {
Triangle::Triangle() : mvp(1.0f), BackColor{1.0f, 1.0f, 1.0f, 1.0f} {
  /* GLfloat vertices[]={ */
  /*   -0.25f,0.0f,0.0f,             0.0f,1.0f,  // left part 0 */
  /*   0.25f,0.0f,0.0f,              1.0f,0.0f,     // right 1 */
  /*   0.0f,0.0f,0.25f,              0.0f,0.0f,       //front 2 */
  /*   0.0f,0.0f,-0.25f,             1.00f,1.0f,     //back 3 */
  /*   0.0f,0.25f,0.0f,              2.0f,1.0f,      //top 4. */
  /*  // * 0.0f,0.0f,0.0f,               0.0f,3.0f       // centre 5 */
  /**/
  /* }; */
  /* GLuint indices[]={ */
  /*   0,4,2, */
  /*   2,4,1, */
  /*   1,4,3, */
  /*   3,4,0, */
  /**/
  /*   1,4,1, */
  /*   0,3,1 */
  /* }; */
  // remove the shader part if u dont want a texture.
  GLfloat vertices[] = {
      //     COORDINATES     /        COLORS      /   TexCoord  //
      -0.05f, 0.0f,  0.05f, 0.0f,   0.0f, -0.05f, 0.0f,  -0.05f, 2.0f,
      0.0f,   0.05f, 0.0f,  -0.05f, 0.0f, 0.0f,   0.05f, 0.0f,   0.05f,
      2.0f,   0.0f,  0.0f,  0.08f,  0.0f, 1.0f,   1.0f};

  // Indices for vertices order
  GLuint indices[] = {0, 1, 2, 0, 2, 3, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4};

  shader = std::make_unique<Shader>("/home/uttkarsh/OpenGL/Renderer_OpenGL/"
                                    "tests/shapes/resources/shaders/f1.shader",
                                    "/home/uttkarsh/OpenGL/Renderer_OpenGL/"
                                    "tests/shapes/resources/shaders/v1.shader");

  texture =
      std::make_unique<Texture>("/home/uttkarsh/OpenGL/Renderer_OpenGL/tests/"
                                "shapes/resources/textures/sky.jpg");
  texture->Bind(0);

  shader->UseUniform1i("u_Texture", 0);

  vao = std::make_unique<VAO>();
  ebo = std::make_unique<EBO>(indices, 18);
  VBO vbo(vertices, 5 * 5 * sizeof(float));

  layout Layout;
  Layout.PushFloat(3);
  Layout.PushFloat(2);

  vbo.Bind();
  vao->addBuffer(vbo, Layout);

  vao->Bind();
  vao->Unbind();
  vbo.Unbind();

  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  camera = std::make_unique<Camera>();
  lighting = std::make_unique<Lighting>();
}
void Triangle::onRender() {
  std::cout<<&this->GLwindow<<std::endl;
  renderer = std::make_unique<Renderer>();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  lighting->onRender();
  lighting->imGuiRender();
  shader->activate();
  shader->UseUniformMat4f("u_MVP", mvp);
  std::vector<float> vec = lighting->ReturnColor();
  shader->UseUniformNumber("u_Color", vec[0], vec[1], vec[2], vec[3]);
  ebo->Bind();
  renderer->Draw(*vao, *ebo, *shader);
}
Triangle::~Triangle() {}
void Triangle::imGuiRender() {
  mvp = camera->MATRIX();

  /* ImGui::ShowDemoWindow(); */
  /* lighting->imGuiRender(); */
}
} // namespace Shapes
