#include "main.h"

//Controller initialize
pros::Controller master(pros::E_CONTROLLER_MASTER);

//Motors initialize
pros::Motor left_mtr(1);
pros::Motor right_mtr(2);

void opcontrol() {

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int pwr = master.get_analog(ANALOG_LEFT_Y);
		int trn = master.get_analog(ANALOG_LEFT_X);

		left_mtr = pwr - trn;
		right_mtr = pwr + trn;
		pros::delay(20);
	}
}
