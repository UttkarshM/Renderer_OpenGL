#include "camera.h"
Camera::Camera(GLfloat defaultVar)
:
  translate(glm::mat4(1.0f)),
  rotate(glm::mat4(1.0f)),
  scaler(glm::mat4(1.0f)),
  local(true),
  xRotate(0.0f),
  yRotate(0.0f),
  zRotate(0.0f),
  matrix(1.0f,1.0f,1.0f),
  translateVec(defaultVar,0.0f,0.0f)
{

}
glm::mat4 Camera::Scale(){
  ImGui::SliderFloat2("Increase the size of x",&matrix.x,1,16);
  scaler = glm::scale(glm::mat4(1.0f),matrix);
  return scaler;
}
glm::mat4 Camera::Rotate(){
  glm::mat4 xmainMatrix(1.0f);
  glm::mat4 ymainMatrix(1.0f);
  glm::mat4 zmainMatrix(1.0f);

  ImGui::SliderFloat("rotate x",&xRotate,0.0f,360.0f);
  ImGui::SliderFloat("rotate y",&yRotate,0.0f,360.0f);
  ImGui::SliderFloat("rotate z",&zRotate,0.0f,360.0f);

  xmainMatrix = glm::rotate(glm::mat4(1.0f),glm::radians(xRotate),glm::vec3(1.0f,0.0f,0.0f));
  ymainMatrix = glm::rotate(glm::mat4(1.0f),glm::radians(yRotate),glm::vec3(0.0f,1.0f,0.0f));
  zmainMatrix = glm::rotate(glm::mat4(1.0f),glm::radians(zRotate),glm::vec3(0.0f,0.0f,1.0f));

  rotate = xmainMatrix*ymainMatrix*zmainMatrix;
  return rotate;
}
glm::mat4 Camera::Translate(){
  ImGui::NewLine();
  ImGui::SliderFloat3("co-ords [x,y,z]",&translateVec.x,-10.0f,10.0f);
  translate=glm::translate(glm::mat4(1.0f),translateVec);
  return translate;
}
glm::mat4 Camera::MATRIX(){
  glm::mat4 local_scaler = Scale();
  glm::mat4 local_rotater = Rotate();
  glm::mat4 local_translate = Translate();
  ImGui::Checkbox("global:",&local);
  glm::mat4 model(1.0f);
  if(!local){
    return local_scaler*model*local_translate*local_rotater;
  }
  return local_scaler*local_rotater*local_translate*model;
}
