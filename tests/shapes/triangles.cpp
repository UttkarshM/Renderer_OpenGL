#include "triangles.h"
#include <GL/gl.h>
#include <memory>
#include <filesystem>

namespace Shapes{
  Triangle::Triangle()
    :translation(0.0f,0.0f,0.0f),
    translationview(0.0f,-0.0f,0.0f),
    scale(1.0f),
    rotatez(45.0f),
    rotatex(45.0f),
    global(true)
    {
    /*   GLfloat vertices[]={ */
    /*   -0.2500f,-0.2500f,-0.25f, 0.0f,0.0f, //bottom left 0 */
    /*   0.2500f,-0.2500f,0.25f,   1.0f,0.0f,//top left 1 */
    /*   0.2500f,0.2500f,0.25f,    1.0f,1.0f,//top right 2 */
    /*   -0.2500f,0.2500f,0.25f,    0.0f,1.0f//bottom right 4 */
    /* }; */
    /* GLuint indices[]={ */
    /*   0,1,2, */
    /*   2,3,0 */
    /* }; */
      GLfloat vertices[]={
        -0.25f,0.0f,0.0f, 0.25f,0.0f,  // left part 0
        0.25f,0.0f,0.0f,  0.75f,0.0f,     // right 1
        0.0f,0.0f,0.25f,  0.0f,0.0f,       //front 2
        0.0f,0.0f,-0.25f, 0.50f,0.0f,     //back 3
        0.0f,0.25f,0.0f,  1.0f,1.0f,      //top 4.
        0.0f,0.0f,0.0f,   0.0f,1.0f       // centre 5
      };
      GLuint indices[]={
        0,4,2,
        2,4,1,
        1,4,3,
        3,4,0,

        0,5,2,
        2,5,1,
        1,5,3,
        3,5,0
      };
    //remove the shader part if u dont want a texture.

    shader = std::make_unique<Shader>("/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/f1.shader",
        "/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/v1.shader");

    texture = std::make_unique<Texture>("/home/uttkarsh/OPENGL/open_gl/include/resources/textures/sky.jpg");
    texture->Bind(0);
    
    shader->UseUniform1i("u_Texture",0);
    
    vao = std::make_unique<VAO>();
    ebo = std::make_unique<EBO>(indices,24);
    VBO vbo(vertices,5*5*sizeof(float));
    
    layout Layout;
    Layout.PushFloat(3);
    Layout.PushFloat(2);

    vbo.Bind();
    vao->addBuffer(vbo,Layout);


    vao->Bind();
    vao->Unbind();
    vbo.Unbind();

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  }
  void Triangle::onRender(){
    renderer = std::make_unique<Renderer>();
    float width = float(windowWidth);
    float height = float(windowHeight);

    glm::mat4 proj = glm::mat4(1.0f);
    glm::mat4 projx = glm::mat4(1.0f);
    glm::mat4 projy = glm::mat4(1.0f);
    glm::mat4 projz = glm::mat4(1.0f);

    /* proj = glm::perspective(glm::radians(rotatex),float(width/height),-0.01f,1.0f); */

    projx = glm::rotate(glm::mat4(1.0f),glm::radians(rotatex),glm::vec3(1.0f,0.0f,0.0f));
    projy = glm::rotate(glm::mat4(1.0f),glm::radians(rotatey),glm::vec3(0.0f,1.0f,0.0f));
    projz = glm::rotate(glm::mat4(1.0f),glm::radians(rotatez),glm::vec3(0.0f,0.0f,1.0f));

    proj=projx*projy*projz;

    glm::mat4 view = glm::translate(glm::mat4(1.0f),translationview);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      shader->activate();
      glm::mat4 model(1.0f);
      ImGui::Checkbox("global",&global);

      //basically the order of multiplying the matrix also matters
      //for local rotationg proj and view need to be on  the right
      glm::mat4 mvp = model*view*proj;
      
      if(!global)
        mvp = proj*view*model;


        glm::mat4 scaler = glm::translate(glm::mat4(0.0f),glm::vec3(scale,scale,scale));
      /* shader->UseUniformNumber("TexColor",0.5f,0.5f,0.5f,1.0f); */
      shader->UseUniformMat4f("u_MVP",mvp);
      ebo->Bind();
      renderer->Draw(*vao,*ebo,*shader);
  }
  Triangle::~Triangle(){

  }
  void Triangle::imGuiRender(){
    ImGui::SliderFloat3("x axis and y axis is controlled by this ",&translationview.x,-5.0f,5.0f);
    Rotate();
    Scale();
  }
  void Triangle::Rotate(){
    ImGui::SliderFloat("rotate x",&rotatex,0.0f,360.0f);
    ImGui::SliderFloat("rotate y",&rotatey,0.0f,360.0f);
    ImGui::SliderFloat("rotate z",&rotatez,0.0f,360.0f);
  }
  void Triangle::Scale(){
    ImGui::SliderFloat("size",&scale,1,20);

  }
}
