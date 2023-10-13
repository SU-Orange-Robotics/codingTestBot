/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       danie                                                     */
/*    Created:      10/6/2023, 5:40:55 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include <cmath>
#include <iostream>
#include "robot-config.h"

using namespace vex;
using namespace std;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here

void leftDrive(double y, double x) {
  LeftMotorA.spin(directionType::fwd, y + x/2, velocityUnits::pct);
  LeftMotorB.spin(directionType::fwd, y + x/2, velocityUnits::pct);
}

// spin(): first parameter to specify forward/backward, second parameter is measure of velocity, third to specify units of velocity
// pct: percentage of power 0-100%

void rightDrive(double y, double x) {
  RightMotorA.spin(directionType::fwd, y - x/2, velocityUnits::pct);
  RightMotorB.spin(directionType::fwd, y - x/2, velocityUnits::pct);
}

void drive(double y, double x) {
  leftDrive(y, x);
  rightDrive(y, x);
}

int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );
   
    while(1) {
        
        // Allow other tasks to run
        this_thread::sleep_for(10);
        drive(Controller1.Axis1.value(), Controller1.Axis2.value());
    }
}
