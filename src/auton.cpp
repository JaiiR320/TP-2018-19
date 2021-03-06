#include "main.h"

int auton;
char color;


void mainAuton(char color){
  //Turn multiplier
  int m = 1;
  if(color == 'b'){
    m = -1;
  }

  /*
  Shoots a ball at one of the flags, drives forward
  to toggle bottom flag then turns depending on side
  stated and flips close cap to correct color
  */
  //hit middle and bottom
    flyWheelSet(180);
    driveDist(-66.0, 120);
    delay(1700);
    driveDist(13.5, 100);
    delay(1500);
    driveTurn(-15 * m, 70);
    delay(400);
    intake_mtr = 127;
    delay(800);
    flyWheelSet(0);

    //turn and drive into cap
    driveTurn(65 * m, 70);
    delay(500);
    driveDist(15.0, 100);
    delay(1000);

    //get other cap
    driveTurn(50.0 * m, 60);
    delay(500);
    driveDist(16.0, 100);
    delay(1500);
    capFlip();
    driveDist(0, 0);
    driveSpeed(0, 0, 1);

    delay(15000);
}

void secondAuton(char color){
  int m = 1;
  if(color == 'b'){
    m = -1;
  }
  //Make an auton to descore some flags on opponent side
}

void safeAuton(char color){
  int m = 1;
  if(color == 'b'){
    m = -1;
  }
  //far flag side
}
