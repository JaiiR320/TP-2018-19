#ifndef FUNCTIONS_H
#define  FUNCTIONS_H

#include "api.h"
using namespace pros;

extern Controller master;
extern Controller partner;

extern Motor left_back;
extern Motor right_back;
extern Motor left_front;
extern Motor right_front;

extern Motor left_lift;
extern Motor right_lift;

extern Motor flywheel_mtr;

extern Motor intake_mtr;

extern Motor cap_flip_mtr;

void liftSpeed(int speed);

void liftSet(int pos, int speed);

void flyWheelSet(int velocity);

void capFlip();

#endif
