/*
 * global.c
 *
 *  Created on: Oct 17, 2022
 *      Author: DELL
 */


#include "global.h"

uint16_t sevenSegment_com_anode [10] = {
		0x1,	//0
		0x4F,	//1
		0x12,	//2
		0x6,	//3
		0x4C,	//4
		0x24,	//5
		0x20,	//6
		0xF,	//7
		0x0,	//8
		0x4,	//9
};

void display_7seg_com_anode(int number) {
	uint16_t num = sevenSegment_com_anode[number];
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, (num>>6)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, (num>>5)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, (num>>4)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, (num>>3)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, (num>>2)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, (num>>1)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, (num>>0)&0x01);

}
