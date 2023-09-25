#include "triangles.h"
#include <GL/gl.h>
#include <memory>
#include <filesystem>

namespace Shapes{
  Triangle::Triangle()
    :translation(0.0f,0.0f,2.0f),
    translationview(0.0f,0.0f,0.0f),
    scale(1.0f),
    rotate(0.0f)
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
    camera = std::make_unique<Camera>(windowWidth,windowHeight,glm::vec3(0.0f,0.0f,2.0f));
  }
  void Triangle::onRender(){
    renderer = std::make_unique<Renderer>();
    float width = float(windowWidth);
    float height = float(windowHeight);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      shader->activate();
      camera->Matrix(45.0f,0.1f,100.0f,*shader,"u_MVP");
      ebo->Bind();
      renderer->Draw(*vao,*ebo,*shader);
  }
  Triangle::~Triangle(){

  }
  void Triangle::imGuiRender(){
    ImGui::SliderFloat3("x axis and y axis is controlled by this ",&translation.x,-10.0f,10.0f);
    ImGui::SliderFloat("x axis and y axis is controlled by this ",&translation.z,-10.0f,10.0f);
    ImGui::SliderFloat("rotate",&rotate,0.0f,90.0f);
  }
  void Triangle::Scale(){
    ImGui::SliderFloat("size",&scale,1,20);

  }
}
