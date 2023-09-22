#pragma once
#include <vector>
#include <string>
#include <functional>
#include <iostream>

namespace test{
  class Test{
    public:
      /* Test() {}; */
      /* virtual ~Test(){} */

      virtual void onUpdate(float deltaTime){}
      virtual void onRender(){}
      virtual void onImGuiRender(){}

  };
  class TestMenu:public Test{
    public:
      TestMenu(Test*& currentTestPointer);
      ~TestMenu();
      template<typename T>
      void RegisterTest(const std::string& name){
        std::cout<<"registering test"<<name<<std::endl;
        m_Tests.push_back(std::make_pair(name,[](){return new T();}));
      }

      void onImGuiRender() override;

    private:
      Test*& current_Test;
      std::vector<std::pair<std::string,std::function<Test*()>>> m_Tests;


  };
}
