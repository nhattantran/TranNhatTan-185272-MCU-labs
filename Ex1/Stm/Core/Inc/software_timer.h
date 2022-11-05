/*
 * software_timer.h
 *
 *  Created on: Oct 9, 2022
 *      Author: DELL
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;

extern int timer1_counter;
extern int timer2_counter;

void setTimer1(int duration);
void setTimer2(int duration);

void runTimer1();
void runTimer2();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
