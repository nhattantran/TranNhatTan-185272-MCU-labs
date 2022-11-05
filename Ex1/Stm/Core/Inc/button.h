/*
 * button.h
 *
 *  Created on: Oct 12, 2022
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

//extern int button1_flag;

int isButton1Pressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
