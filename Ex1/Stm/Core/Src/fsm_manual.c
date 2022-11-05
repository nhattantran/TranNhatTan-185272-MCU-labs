/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2022
 *      Author: DELL
 */


#include "fsm_manual.h"
#include "traffic.h"

void fsm_manual_run(){
	switch (status) {
	case MAN_RED:
		//TODO
		turn_on_red();
		if (timer1_flag == 1) {
			status = RED;
			setTimer1(500);
		}
		if (isButton1Pressed() == 1) {
			status = MAN_YELLOW;
			setTimer1(500);
		}
		break;
	case MAN_GREEN:
		turn_on_green();
		if (timer1_flag == 1) {
			status = GREEN;
			setTimer1(500);
		}
		if (isButton1Pressed() == 1) {
			status = MAN_RED;
			setTimer1(500);
		}
		break;
	case MAN_YELLOW:
		turn_on_yellow();
		if (timer1_flag == 1) {
			status = YELLOW;
			setTimer1(200);
		}
		if (isButton1Pressed() == 1) {
			status = MAN_GREEN;
			setTimer1(500);
		}
break;
	default:
		break;
	}
}
