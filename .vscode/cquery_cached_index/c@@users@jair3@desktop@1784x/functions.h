#ifndef  FUNCTIONS_H
#define  FUNCTIONS_H
#include "main.h"

extern Controller master;

extern Motor left_drive;
extern Motor right_drive;

extern Motor left_lift;
extern Motor right_lift;

extern Motor flywheel_mtr;

extern Motor intake_mtr;

extern Motor cap_flip_mtr;

extern ADIGyro gyro;

void driveSpeed(int left, int right, int side);

void driveDist(float dist, int speed); // in inches, linear distnance

void driveTurn(double degrees, int speed);

void liftSpeed(int left, int right);

void liftSet(int pos, int speed);

void flyWheelSet(int pwr);

void capFlip(int speed);

void square();

#endif
