#include "main.h"

Controller master(E_CONTROLLER_MASTER);

Motor left_back(1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor left_front(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor right_back(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_front(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor left_lift(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_ROTATIONS);
Motor right_lift(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);

Motor flywheel_mtr(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);

Motor intake_mtr(8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);

Motor cap_flip_mtr(9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);


void driveSpeed(int left, int right, int side){
	if(side == 1){
		left_front.move(left);
		left_back.move(left);
		right_front.move(right);
		right_back.move(right);

	}
	if(side == -1){
		left_front.move(right * -1);
		left_back.move(right * -1);
		right_front.move(left * -1);
		right_back.move(left * -1);

	}
}

void driveDist(float dist, int speed){ //IMPORTANT, Distance in Inches
	dist = ((dist / 12.56) * 360);    //Converts desired inches into degrees

	left_front.move_relative(dist, speed);
	left_back.move_relative(dist, speed);
	right_front.move_relative(-dist, speed);
	right_back.move_relative(-dist, speed);

}

void driveTurn(double degrees, int speed){ //Pos degrees turns right
	//Find arclength of circle with d = diagonal between opposite wheels
	//drive arclength with theta = to degree
	/*double rad = 9.55;

	double arclength = 2 * 3.14159 * rad * (degrees / 360);

	double dist = (arclength / 12.56) * 360;
	dist /= 2;
*/

	double dist = degrees;

	left_front.move_relative(dist, speed);
	left_back.move_relative(dist, speed);
	right_front.move_relative(dist, speed);
	right_back.move_relative(dist, speed);

}

void liftSpeed(int speed){
	left_lift.move(speed);
	right_lift.move(speed);
}

//figure out optimal rotations/position
void liftSet(int pos, int speed){
	left_lift.move_relative(pos, speed);
	right_lift.move_relative(pos, speed);
}

void capFlip(){
	cap_flip_mtr.move_relative(180, 100);
}

void flyWheelSet(int pwr){
	flywheel_mtr = pwr;
}
