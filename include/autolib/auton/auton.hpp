#pragma once

#include "okapi/api.hpp"
#include "autolib/robot/robot.hpp"
#include <memory>
#include <map>
#include <string>

namespace autolib{

using namespace okapi;

class Auton{
    public:
    Auton( const std::shared_ptr<Robot> &irobot );

    void add( const std::string &id, std::function< void(std::shared_ptr<Robot>)> iroutine );
    void run( const std::string &id );

    protected:
    friend class Selector;

    const std::shared_ptr<Robot> robot { nullptr };
    std::map<std::string, std::function<void(std::shared_ptr<Robot>)>> routines;
};

}//autolib
