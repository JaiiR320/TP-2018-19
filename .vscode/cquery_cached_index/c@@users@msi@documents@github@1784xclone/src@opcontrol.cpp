/*
Jair Meza
9/25/18
1784X
*/
#include "main.h"

void opcontrol(){
	int left, right;
	int side = 1;

	while(true) {
		cap_flip_mtr.set_zero_position(cap_flip_mtr.get_position());

		//Drive
		left = master.get_analog(ANALOG_LEFT_Y);
		right = master.get_analog(ANALOG_RIGHT_Y);

		if(master.get_digital(DIGITAL_L1) == 1){
			side = -1;
		}
		if(master.get_digital(DIGITAL_L2) == 1){
			side = 1;
		}
		driveSpeed(left, right, side);

		//Cap Flip
		if(master.get_digital(DIGITAL_A) == 1){
			capFlip();
			while(master.get_digital(DIGITAL_A) == 1){
				delay(5);
			}
		}

		//Lift
		if(master.get_digital(DIGITAL_R1) == 1){
			liftSpeed(100);
		}
		else if(master.get_digital(DIGITAL_R2) == 1){
			liftSpeed(-100);
		}
		else{
			liftSpeed(0);
		}

		//Fly wheel, L Up = set, L Down = stop
		if(master.get_digital(DIGITAL_L1) == true){
			flyWheelSet(127);
		}
		else if(master.get_digital(DIGITAL_L2) == true){
			flyWheelSet(0);
		}

		delay(20);
	}
}
