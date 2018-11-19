#include "main.h"

void autonomous() {
  switch(auton){
    case 1: mainAuton(color);
    case 2: secondAuton(color);
    case 3: safeAuton(color);
    case 0: delay(20);
  }
  if(COMPETITION_AUTONOMOUS == true){
    delay(20);
    auton = 0;
  }
}
