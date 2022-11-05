/*
 * traffic.c
 *
 *  Created on: Oct 12, 2022
 *      Author: DELL
 */


#include "traffic.h"

void turn_on_red() {
	HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, SET);
	HAL_GPIO_WritePin(led2_GPIO_Port, led2_Pin, RESET);
}

void turn_on_green() {
	HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, RESET);
	HAL_GPIO_WritePin(led2_GPIO_Port, led2_Pin, SET);
}

void turn_on_yellow() {
	HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, SET);
	HAL_GPIO_WritePin(led2_GPIO_Port, led2_Pin, SET);
}
