#pragma once

#include "display/lvgl.h"
#include "lib7842/api.hpp"
#include "api.h"

using namespace lib7842;

namespace Screen{

void init();

extern std::shared_ptr<GUI::Screen> screen;
extern pros::Task screenTask;

}
