/*
 * global.h
 *
 *  Created on: Oct 17, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define STATE12		1
#define STATE21		2

extern int state;

extern uint16_t sevenSegment_com_anode[10];

void display_7seg_com_anode(int number);

#endif /* INC_GLOBAL_H_ */
