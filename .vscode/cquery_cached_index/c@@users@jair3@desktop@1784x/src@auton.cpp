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

  //Shoot mid or high flag
  flyWheelSet(127);
  delay(2000);
  intake_mtr = 127;
  delay(1500);

  //Toggle bottom
  driveDist(42.0, 127);
  delay(2500);
  driveDist(-30.0, 127); //!!!!!!!!!!!   CHECK    !!!!!!!!!
  delay(2000);

  //Side specific turn
  driveTurn(90.0 * m, 100);
  delay(1000);

  //Arm down and capflip
  liftSet(-225, 100); //down
  delay(500);
  driveDist(16.0, 127); //!!!!!!!!!!!   CHECK    !!!!!!!!!
  delay(700);
  liftSet(-100, 100); //up
  capFlip(); //flip
  delay(200);
  liftSet(-230, 100); //down

  //Drive back
  driveDist(-14.0, 127); //!!!!!!!!!!!   CHECK    !!!!!!!!!
}

void secondAuton(char color){
  int m = 1;
  if(color == 'b'){
    m = -1;
  }

}

void safeAuton(char color){
  int m = 1;
  if(color == 'b'){
    m = -1;
  }

  //Turn
  driveTurn(36.9 * m, 100);
  delay(700);

  //lift drop and cap flip
  liftSet(-225, 100);
  delay(600);
  driveDist(48.0, 100); //!!!!!!!!!!!   CHANGE    !!!!!!!!!
  delay(2500);
  liftSet(-100, 100);
  capFlip();

  //Allign with platform
  driveDist(-8, 100); //!!!!!!!!!!!   CHANGE    !!!!!!!!!
  delay(700);
  driveTurn(53.1 * m, 100);
  delay(500);
  liftSet(-225, 100);
  driveDist(-60, 120); //!!!!!!!!!!!   CHANGE    !!!!!!!!!
  delay(3000);
}
