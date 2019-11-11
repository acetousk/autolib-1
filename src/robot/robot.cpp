#include "autolib/robot/robot.hpp"

#include "okapi/api.hpp"

namespace autolib{

Robot::Robot(
  const std::shared_ptr<ChassisController> &idrive ,
  const std::shared_ptr<MotorGroup>        &iintake,
  const std::shared_ptr<MotorGroup>        &ilift  ,
  const std::shared_ptr<MotorGroup>        &iother ,
  const std::shared_ptr<MotorGroup>        &iother2):
    drive(idrive),
    intake(iintake),
    lift(ilift),
    other(iother),
    other2(iother2){}

void Robot::setDrive ( const std::shared_ptr<ChassisController> &idrive  ){
  drive = idrive;
}
void Robot::setIntake( const std::shared_ptr<MotorGroup>        &iintake ){
  intake = iintake;
}
void Robot::setLift  ( const std::shared_ptr<MotorGroup>        &ilift   ){
  lift = ilift;
}
void Robot::setOther ( const std::shared_ptr<MotorGroup>        &iother  ){
  other = iother;
}
void Robot::setOther2( const std::shared_ptr<MotorGroup>        &iother2 ){
  other2 = iother2;
}

std::shared_ptr<ChassisController> Robot::getDrive(){
  if( drive != nullptr )
    return drive;
  else{
    printf("Autolib Robot getDrive Error: need to set drive to !nullptr before calling it\n");
    return nullptr;
  }
}

std::shared_ptr<MotorGroup> Robot::getIntake(){
  if( intake != nullptr )
    return intake;
  else{
    printf("Autolib Robot getDrive Error: need to set drive to !nullptr before calling it\n");
    return nullptr;
  }
}

std::shared_ptr<MotorGroup> Robot::getLift(){
  if( lift != nullptr )
    return lift;
  else{
    printf("Autolib Robot getDrive Error: need to set drive to !nullptr before calling it\n");
    return nullptr;
  }
}
std::shared_ptr<MotorGroup> Robot::getOther(){
  if( other != nullptr )
    return other;
  else{
    printf("Autolib Robot getDrive Error: need to set drive to !nullptr before calling it\n");
    return nullptr;
  }
}
std::shared_ptr<MotorGroup> Robot::getOther2(){
  if( other2 != nullptr )
    return other2;
  else{
    printf("Autolib Robot getDrive Error: need to set drive to !nullptr before calling it\n");
    return nullptr;
  }
}

}
