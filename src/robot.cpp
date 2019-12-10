#include "robot/robot.hpp"

#include <memory>

using namespace okapi;

namespace Robot{

std::shared_ptr<MotorGroup> intake = std::make_shared<MotorGroup>( MotorGroup({5, -6}) );
std::shared_ptr<MotorGroup> tray = std::make_shared<MotorGroup>( MotorGroup({1})  );
std::shared_ptr<MotorGroup> other = nullptr;
std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
  .withMotors( {-9, 10}, {2,3} )
  .withDimensions( AbstractMotor::GearsetRatioPair{ AbstractMotor::gearset::green }, { 10.2101761242_in, 10.5_in } )
  .build();

std::shared_ptr<ChassisModel> model = nullptr;
std::shared_ptr<CustomOdometry> odom = nullptr;

}
