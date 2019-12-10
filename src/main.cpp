#include "main.h"

#include "autolib/api.hpp"
#include "okapi/api.hpp"

#include <memory>

using namespace autolib;

void initialize() {
	//wait for adi ports
	pros::delay(500);
	printf("Initialize\n");

	

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
