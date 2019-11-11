#pragma once

#include "okapi/api.hpp"

#include <initializer_list>
#include <memory>
#include <vector>

namespace autolib{

using namespace okapi;

class Robot{
    public:
    Robot(
      const std::shared_ptr<ChassisController> &idrive  = nullptr ,
      const std::shared_ptr<MotorGroup>        &iintake = nullptr ,
      const std::shared_ptr<MotorGroup>        &ilift   = nullptr ,
      const std::shared_ptr<MotorGroup>        &iother  = nullptr ,
      const std::shared_ptr<MotorGroup>        &iother2 = nullptr );

    void setDrive ( const std::shared_ptr<ChassisController> &idrive  );
    void setIntake( const std::shared_ptr<MotorGroup>        &iintake );
    void setLift  ( const std::shared_ptr<MotorGroup>        &ilift   );
    void setOther ( const std::shared_ptr<MotorGroup>        &iother  );
    void setOther2( const std::shared_ptr<MotorGroup>        &iother2 );

    std::shared_ptr<ChassisController> getDrive();
    std::shared_ptr<MotorGroup>        getIntake();
    std::shared_ptr<MotorGroup>        getLift();
    std::shared_ptr<MotorGroup>        getOther();
    std::shared_ptr<MotorGroup>        getOther2();

    private:
    //change these
    std::shared_ptr<ChassisController> drive  {nullptr};
    std::shared_ptr<MotorGroup>        intake {nullptr};
    std::shared_ptr<MotorGroup>        lift   {nullptr};
    std::shared_ptr<MotorGroup>        other  {nullptr};
    std::shared_ptr<MotorGroup>        other2 {nullptr};
};

}//autolib
