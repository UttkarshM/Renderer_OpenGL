#pragma once

#include<vector>
#include<string>
#include<functional>
#include<iostream>


namespace Shapes{
  class Shape{
    public:
      Shape(){};
      /* ~Shape(){}; */
      virtual void onRender(){};
      virtual void imGuiRender(){};
  };
}
