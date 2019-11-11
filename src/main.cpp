#include "main.h"

#include "autolib/api.hpp"
#include "okapi/api.hpp"

#include <memory>

using namespace autolib;

std::shared_ptr<Robot> robot;

void initialize() {
	//initialize robot class
	robot = std::make_shared<Robot>();

	//use chassis controller builder
	auto chassis = okapi::ChassisControllerBuilder()
		.withMotors( 
			okapi::MotorGroup( { 11, 12 } ),
			okapi::MotorGroup( { 19, 20 } )
		)
		//.withSensors()
		//.withGains()
		.withOdometry()
		//.withDerivativeFilters()
		.withDimensions( 
			{ AbstractMotor::gearset::green, .6 },
			{2.25_in, 13_in }
		)
		.withMaxVelocity( 200 )
		.withMaxVoltage( 14000 )
		//.withOdometryTimeUtilFactory()
		.buildOdometry();

	//initialize robot's drive controller with chassis
	robot->setDrive( chassis );

	//initialize robot's intake
	robot->setIntake( std::make_shared<MotorGroup>(MotorGroup({ -2, 9 })) );

	//initialize robot's tray
	robot->setOther( std::make_shared<MotorGroup>(MotorGroup({ -1, 10 })) );
}

void disabled() {}
void competition_initialize() {}

void autonomous() {

}

void opcontrol() {
	while(true){
		pros::delay(20);
	}
}
