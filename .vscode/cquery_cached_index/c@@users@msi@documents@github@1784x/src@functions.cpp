#include "main.h"

Controller master(E_CONTROLLER_MASTER);

Motor left_drive(1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor right_drive(2, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor left_lift(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor right_lift(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor flywheel_mtr(5, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);

Motor intake_mtr(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

Motor cap_flip_mtr(8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

void driveSpeed(int left, int right, int side){
	if(side == 1){
		left_drive.move(left);
		right_drive.move(right);
	}
	if(side == -1){
		left_drive.move(right * -1);
		right_drive.move(left * -1);
	}
}

void driveSet(int pos, int speed){
	left_drive.move_relative(pos, speed);
	right_drive.move_relative(pos, speed);
}

void liftSpeed(int left, int right){
	left_lift.move(left);
	right_lift.move(right);
}

void liftSet(int pos, int speed){
	left_lift.move_relative(pos, speed);
	right_lift.move_relative(pos, speed);
}

void capFlip(int speed){
	cap_flip_mtr.move_relative(180, speed);
}
