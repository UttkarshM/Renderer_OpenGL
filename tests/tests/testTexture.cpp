#include "testTexture.h"
#include "test.h"
#include <glad/glad.h>
#include <memory>
#include "../../external/imgui/imgui.h"
#include "../../external/imgui/imgui_impl_opengl3.h"
#include "../../external/imgui/imgui_impl_glfw.h"

#define windowWidth 960
#define windowHeight 540



namespace test{
  TestTexture::TestTexture()
  :translationA(200,200,0),translationB(400,200,0)
  {
  GLfloat vertices[]={
      -50.0f,-50.0f, 0.0f,0.0f, //bottom left 0
      50.0f,-50.0f, 1.0f,0.0f, //top left 1
      50.0f,50.0f, 1.0f,1.0f, //top right 2
      -50.0f,50.0f , 0.0f,1.0f //bottom right 4
    };
    GLuint indices[]={
      0,1,2,
      2,3,0
    };
    //making a local scope so that all objects created get destroyed.

  Program = std::make_unique<Shader>("/home/uttkarsh/OPENGL/open_gl/include/resources/shaders/f1.shader"
      ,"/home/uttkarsh/OPENGL/open_gl/include/resources/shaders/v1.shader");
  vao = std::make_unique<VAO>();
  ebo = std::make_unique<EBO>(indices,6);
  VBO vbo(vertices,4*4*sizeof(float));
  layout Layout;
  vbo.Bind();
  EBO ebo(indices,6);
  ebo.Bind();

  Layout.PushFloat(2);
  Layout.PushFloat(2);

  vao->addBuffer(vbo,Layout);
//its an orthographic matrix that is used to multiple to our vertices
// cause bfr we were viewing objects in percpective view

  float width = float(windowHeight);
  float height = float(windowWidth);
  glm::mat4 proj = glm::ortho(0.0f,width,0.0f,height,-1.0f,1.0f);
  glm::mat4 view = glm::translate(glm::mat4(1.0f),glm::vec3(0,0,0));


  texturer = std::make_unique<Texture>("/home/uttkarsh/OPENGL/open_gl/include/resources/textures/test1.jpg");
  texturer->Bind(0);
  Program->UseUniform1i("u_Texture",0);
  vao->Bind();
  vao->Unbind();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  vbo.Unbind();
  }
  TestTexture::~TestTexture()
  {

  }
  void TestTexture::onUpdate(float deltaTime)
  {

  }
  void TestTexture::onRender()
  {
    Renderer renderer;

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  float width = float(windowHeight);
  float height = float(windowWidth);
  glm::mat4 proj = glm::ortho(0.0f,width,0.0f,height,-1.0f,1.0f);
  glm::mat4 view = glm::translate(glm::mat4(1.0f),glm::vec3(0,0,0));
  {
    Program->activate();
      glm::mat4 modelA = glm::translate(glm::mat4(1.0f),translationA);
      glm::mat4 mvp = proj*view*modelA;
      Program->UseUniformMat4f("u_MVP",mvp);
      texturer->Bind();
      ebo->Bind();
      renderer.Draw(*vao,*ebo,*Program);
    }
    {
      Program->activate();
      glm::mat4 modelB = glm::translate(glm::mat4(1.0f),translationB);
      glm::mat4 mvp = proj* view* modelB;
      Program->UseUniformMat4f("u_MVP",mvp);
      texturer->Bind();
      ebo->Bind();
      renderer.Draw(*vao,*ebo,*Program);
    }
  }
  void TestTexture::onImGuiRender()
  {
    ImGui::SliderFloat2("x-axis and y- axis movement Model A",&translationA.x, 50.0f, 320.0f);
    ImGui::SliderFloat2("x-axis and y- axis movement Model B.",&translationB.x, 300.0f, 500.0f);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    
  }
}
