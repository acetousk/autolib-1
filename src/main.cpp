#include "main.h"

#include "autolib/api.hpp"
#include "okapi/api.hpp"

#include <memory>

using namespace autolib;

std::shared_ptr<Robot> robot;
std::shared_ptr<Auton> auton;
std::shared_ptr<Selector> selector;

void inothing(std::shared_ptr<Robot> robot){
	//literally nothing
}
std::function<void(std::shared_ptr<Robot>)> nothing = inothing;

void initialize() {
	//wait for adi ports
	pros::delay(500);
	printf("Initialize\n");

	//initialize robot class
	robot = std::make_shared<Robot>();

	//use chassis controller builder
	auto chassis = okapi::ChassisControllerBuilder()
		.withMotors( 
			MotorGroup( { 11, 12 } ),
			MotorGroup( { 19, 20 } )
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

	//initialize robot's lift
	//robot->setLift( std::make_shared<MotorGroup>(MotorGroup({ -2, 9 })) );

	//initialize robot's tray
	robot->setOther( std::make_shared<MotorGroup>(MotorGroup({ -1, 10 })) );

	//initialize robot's other2
	//robot->setOther( std::make_shared<MotorGroup>(MotorGroup({ -1, 10 })) );

	auton = std::make_shared<Auton>( robot );
	auton->add( "nothing", nothing );

//	pros::delay(50);//?

	selector = std::make_shared<Selector>( auton );
	selector->init();
	selector->toggle("nothing");

}

void disabled() {
	printf("Disabled\n");
}

void competition_initialize() {
	printf("Competition Initialize\n");
}

void autonomous() {
	printf("Autonomous\n");
}

void opcontrol() {
	printf("opControl\n");

	while(true){
		pros::delay(20);
	}
}
