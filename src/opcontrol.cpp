/*
Jair Meza
9/25/18
1784X
*/
#include "main.h"

void opcontrol(){
	double power, turn;
	int side = 1;

	while(true) {
		cap_flip_mtr.set_zero_position(cap_flip_mtr.get_position());

		//Drive
		power = master.get_analog(ANALOG_LEFT_Y);
		turn = master.get_analog(ANALOG_RIGHT_X) / 2;

		if(master.get_digital(DIGITAL_UP) == 1){
			side = -1;
		}
		if(master.get_digital(DIGITAL_DOWN) == 1){
			side = 1;
		}


		driveSpeed(power + turn, power - turn, side);

		//Cap Flip
		if(master.get_digital(DIGITAL_A) == 1){
			capFlip();
			while(master.get_digital(DIGITAL_A) == 1){
				delay(5);
			}
		}

		//Lift
		if(master.get_digital(DIGITAL_R1) == 1){
			liftSpeed(120);
		}
		else if(master.get_digital(DIGITAL_R2) == 1){
			liftSpeed(-120);
		}
		else{
			liftSpeed(0);
		}

		//Fly wheel set
		if(master.get_digital(DIGITAL_Y) == true){
			flyWheelSet(180);
		}
		else if(master.get_digital(DIGITAL_B) == true){
			flyWheelSet(0);
		}

		//Intake set
		if(master.get_digital(DIGITAL_L1) == true){
			intake_mtr = 127; //in
		}
		else if(master.get_digital(DIGITAL_L2) == true){
			intake_mtr = -127; //out
		}
		else{
			intake_mtr = 0;
		}

		delay(20);
	}
}
