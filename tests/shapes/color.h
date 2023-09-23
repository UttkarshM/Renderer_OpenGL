#pragma once

#include "shapes.h"
namespace Shapes{
  class Color:public Shape{
    public:
      Color();
      ~Color();
      void onRender() override;
      void imGuiRender() override;
    private:
      float BackColor[4];

  };
}
