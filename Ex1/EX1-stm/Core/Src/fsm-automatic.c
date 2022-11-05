/*
 * fsm-automatic.c
 *
 *  Created on: Oct 17, 2022
 *      Author: DELL
 */


#include "fsm_automatic.h"

int state;

int check = 0;


void fsm_automatic() {

	switch (state) {
	case STATE12:
//		display_7seg_com_anode(1);
		if (check == 0 ) {
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display_7seg_com_anode(1);
			check = 1;

		}
		if (check == 1) {
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			display_7seg_com_anode(2);
			check = 0;
		}
		if (timer1_flag == 1){
			state = STATE21;
			setTimer1(4);
		}
		break;
	case STATE21:
//		display_7seg_com_anode(2);
		if (check == 0) {
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display_7seg_com_anode(2);
			check = 1;
		}
		if (check == 1) {
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			display_7seg_com_anode(1);
			check = 0;
		}
		if (timer1_flag == 1){
			state = STATE12;
			setTimer1(4);
		}
		break;
	default:
		break;
	}
}
