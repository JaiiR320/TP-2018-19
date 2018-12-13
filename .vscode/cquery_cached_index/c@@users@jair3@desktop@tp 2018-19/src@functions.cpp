#include "main.h"

Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_PARTNER);

Motor left_back(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor left_front(12, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor right_back(1, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_front(14, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor lift(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);

Motor flywheel_b(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);
Motor flywheel_a(6, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_ROTATIONS);

Motor intake_mtr(8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_ROTATIONS);

Motor cap_flip_mtr(9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

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
	flywheel_a.move(velocity);
	flywheel_b.move(velocity);
}
