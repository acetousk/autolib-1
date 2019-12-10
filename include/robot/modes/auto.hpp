#pragma once

#include "robot/robot.hpp"

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace Auto{

void run();
void runAuto(const std::string& id);

extern std::string routine;
extern std::vector<std::pair<const std::string&, const std::function<void()>&>> routines;

void initAuto();
extern bool isInitAuto;

}//Auto
