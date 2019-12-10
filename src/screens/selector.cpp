#include "robot/screens/selector.hpp"

#include "robot/modes/auto.hpp"
#include "robot/screens/screen.hpp"
#include "lib7842/api/gui/selector.hpp"

using namespace lib7842::GUI;

namespace Screen{

void initSelector(){
  screen->makePage<Selector>("Selector")
    .button("simpleForward", [&]() { Auto::routine = "simpleForward"; })
    .button("simpleBackward", [&]() { Auto::routine = "simpleBackward"; })
    .build();

  screen->makePage<Selector>("Runner")
    .button("simpleForward", [&]() { Auto::runAuto("simpleForward"); })
    .button("simpleBackward", [&]() { Auto::runAuto("simpleBackward"); })
    .build();
}

}//Screen
