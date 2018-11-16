#include "main.h"

Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_MASTER);

Motor left_back(1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor left_front(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor right_back(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_front(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor lift(5, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);

Motor flywheel_mtr(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);

Motor intake_mtr(8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_ROTATIONS);

Motor cap_flip_mtr(9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);


void driveSpeed(double left, double right, int side){
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
	dist = ((dist / 12.566) * 360);    //Converts desired inches into degrees

	left_front.move_relative(dist, speed);
	left_back.move_relative(dist, speed);
	right_front.move_relative(-dist, speed);
	right_back.move_relative(-dist, speed);

}

void driveTurn(double degrees, int speed){ //Pos degrees turns right
	double dist = degrees;

	left_front.move_relative(dist, speed);
	left_back.move_relative(dist, speed);
	right_front.move_relative(dist, speed);
	right_back.move_relative(dist, speed);

}

void liftSpeed(int speed){
	lift.move(speed);
}

void liftSet(int pos, int speed){
	lift.move_relative(pos, speed);
}

void capFlip(){
	cap_flip_mtr.move_relative(180, 100);
}

void flyWheelSet(int velocity){

	flywheel_mtr.move_velocity(velocity);
}
