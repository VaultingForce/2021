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
vex::competition Competition;
vex::brain Brain;
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
    
    //Brain Output - VALUES
    Brain.Screen.clearLine(0, color::black); //Clear Screen's Line 0
    Brain.Screen.clearLine(1, color::black); //Clear Screen's Line 1
    Brain.Screen.clearLine(2, color::black); //Clear Screen's Line 2
    Brain.Screen.setCursor(1,1); //Set Cursor to 1,1
    Brain.Screen.print("Left Motor : %f velocity", LeftStickAxis); //Write Left Motor's Spins Values to the Brain's Screen
    Brain.Screen.setCursor(2,1); //Set Cursor to 2,1
    Brain.Screen.print("Right Motor : %f velocity", RightStickAxis); //Write Right Motor's Spin Values to the Brain's Screen
    Brain.Screen.render(); //push data to the LCD all at once to prevent image flickering
    //Brain Output-End
    }
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
