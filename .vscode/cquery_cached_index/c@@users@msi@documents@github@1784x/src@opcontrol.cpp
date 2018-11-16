/*
Jair Meza
9/25/18

Notes:
Positive is always forwards/up/in

keep left and right motor powers positive if going forwards
*/


#include "main.h"

void opcontrol(){
	int left, right;
	int initialPos;
	int side = 1;

	while (true) {
		cap_flip_mtr.set_zero_position(cap_flip_mtr.get_position());

		left = master.get_analog(ANALOG_LEFT_Y);
		right = master.get_analog(ANALOG_RIGHT_Y);

		if(master.get_digital(DIGITAL_L1) == 1){
			side = -1;
		}
		if(master.get_digital(DIGITAL_L2) == 1){
			side = 1;
		}

		driveSpeed(left, right, side);


		if(master.get_digital(DIGITAL_R2) == 1){
			capFlip(110);

			while(master.get_digital(DIGITAL_R2) == 1){
				delay(5);
			}
		}

		if(master.get_digital(DIGITAL_L1) == true){
			liftSpeed(127, 127);
		}
		else if(master.get_digital(DIGITAL_L2) == true){
			liftSpeed(-127, -127);
		}
		else{
			liftSpeed(0, 0);
		}

		delay(20);
	}
}
