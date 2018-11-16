/*
Jair Meza
9/25/18
1784X
*/
#include "main.h"

void opcontrol(){
	double left, right;
	int side = 1;

	while(true) {
		cap_flip_mtr.set_zero_position(cap_flip_mtr.get_position());

		//Drive
		left = master.get_analog(ANALOG_LEFT_Y);
		right = master.get_analog(ANALOG_RIGHT_Y);

		if(master.get_digital(DIGITAL_UP) == 1){
			side = -1;
		}
		if(master.get_digital(DIGITAL_DOWN) == 1){
			side = 1;
		}

		if(side == 1){
			left_front.move(left);
			left_back.move(left);
			right_front.move(right);
			right_back.move(right);

		}
		else if(side == -1){
			left_front.move(right * -1);
			left_back.move(right * -1);
			right_front.move(left * -1);
			right_back.move(left * -1);

		}

		//Cap Flip
		if(partner.get_digital(DIGITAL_A) == 1){
			capFlip();
			while(partner.get_digital(DIGITAL_A) == 1){
				delay(5);
			}
		}

		//Lift
		if(partner.get_digital(DIGITAL_R1) == 1){
			liftSpeed(127);
		}
		else if(partner.get_digital(DIGITAL_R2) == 1){
			liftSpeed(-127);
		}
		else if(partner.get_digital(DIGITAL_R2) == 0){
			liftSpeed(0);
		}

		//Fly wheel set
		if(partner.get_digital(DIGITAL_Y) == true){
			flyWheelSet(180);
		}
		else if(partner.get_digital(DIGITAL_B) == true){
			flyWheelSet(0);
		}

		//Intake set
		if(partner.get_digital(DIGITAL_L1) == true){
			intake_mtr = 127; //in
		}
		else if(partner.get_digital(DIGITAL_L2) == true){
			intake_mtr = -127; //out
		}
		else{
			intake_mtr = 0;
		}

		delay(20);
	}
}
