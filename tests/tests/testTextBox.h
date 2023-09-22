#include "test.h"
#include <string>
namespace test{
  class TextBox:public Test{
    public:
      TextBox();
      ~TextBox();
      void onUpdate(float deltaTime) override;
      void onRender() override;
      void onImGuiRender() override;
    private:
      std::string stre;
  };
}
