#include "../external/glm/glm/glm.hpp"
#include "../external/glm/glm/gtc/matrix_transform.hpp"
#include "../external/glm/glm/ext/scalar_constants.hpp"
#include "../external/glm/glm/ext/matrix_clip_space.hpp"
#include "../external/glm/glm/gtx/string_cast.hpp"

#include <iostream>

int main(){
  /* glm::vec3 A(3.0f); */
  /* glm::vec3 B(7.5f); */
  /* glm::mat4 C(1.0f); */
  /**/
  /* //normalize returns a unit vector with the same direction */
  /* float f = glm::dot(glm::normalize(A),glm::normalize(B)); */
  /* float f1 = glm::dot(A,B); */
  /* std::cout<<f<<std::endl; */
  /* std::cout<<f1<<std::endl; */
  /* std::cout<< glm::to_string(A)<<std::endl; */
  /* std::cout<< glm::to_string(glm::normalize(A))<<std::endl; */
  /* std::cout<< glm::to_string(B)<<std::endl; */
  /* std::cout<< glm::to_string(C)<<std::endl; */
  /* std::cout<< glm::to_string(glm::cross(A,B))<<std::endl; */



  glm::vec3 pointa(1.0f,2.0f,-1.5f);
  glm::vec3 pointnew = glm::normalize(pointa);
  glm::vec3 pointc(1.0f,2.0f,-1.5f);
  glm::vec3 pointb(0.0f,1.0f,1.5f);


  float dotproduct = glm::dot(pointc,pointb);
  std::cout<< std:: acos(dotproduct) * 180.0f/M_PI //the answer that is given is in radians hence we are converting it into degrees
                                                    <<std::endl;
  glm::vec3 crossproduct = glm::cross(pointa,pointb);
  std::cout<<glm::to_string(crossproduct)<<std::endl;


  return 0;
}
