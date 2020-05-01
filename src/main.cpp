/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Walkeriyecrew                                             */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Vaulting Force 2020-2021 Robot Code                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
using namespace vex;
competition Competition;
void pre_auton(void) {vexcodeInit();}
void autonomous(void) {}
void usercontrol(void) {
  while (1) {
    //Variables
    double LeftStickAxis = Controller1.Axis3.value(); //Controller's Axis 3 Value (+1 to -1)
    double RightStickAxis = Controller1.Axis2.value(); //Controller's Axis 2 Value (+1 to -1)
    //Variables-End

    //Drivetrain - TANK DRIVE
    LeftMotor.spin(vex::directionType::fwd, LeftStickAxis, vex::velocityUnits::pct); //Left Motor's Spin Situation (diretionType, velocity, velocity lib)
    RightMotor.spin(vex::directionType::fwd, RightStickAxis, vex::velocityUnits::pct); //Right Motor's Spin Situation (diretionType, velocity, velocity lib)
    //Drivetrain - END
    wait(20, msec);
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
