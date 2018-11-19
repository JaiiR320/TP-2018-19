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
		turn = master.get_analog(ANALOG_LEFT_X);

		driveSpeed(power + turn, power - turn, side);

		liftSpeed(master.get_analog(ANALOG_RIGHT_Y));

	if(master.get_digital(DIGITAL_DOWN) == 1){
		side = -1;
	}
	if(master.get_digital(DIGITAL_UP) == 1){
		side = 1;
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
			flyWheelSet(120);
		}
		else if(partner.get_digital(DIGITAL_B) == true){
			flyWheelSet(0);
		}

		//Intake set
		if(partner.get_digital(DIGITAL_L1) == true){
			intake_mtr.move(127); //in
		}
		else if(partner.get_digital(DIGITAL_L2) == true){
			intake_mtr.move(-127); //Out
		}
		else{
			intake_mtr.move(0);
		}

		delay(20);
	}
}
