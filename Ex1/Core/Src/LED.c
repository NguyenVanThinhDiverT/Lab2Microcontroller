/*
 * LED.c
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */

#include "LED.h"

int ENstatus = 0;

/* 7SEGMENT Fuction */
void clear7SEG(){
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
			SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
}
void display7SEG(int num){
	if(num >= 0 && num < 10){
		switch (num) {
			case 0:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG4_Pin | SEG5_Pin, 0);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, 0);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin |
										 SEG4_Pin | SEG6_Pin, 0);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG6_Pin, 0);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |
										 SEG5_Pin | SEG6_Pin, 0);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin |
										 SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |
										 SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
				break;
			case 8:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 9:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
		}
	}
}

/* Blink Led */
void blinkLED()
{
  HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
}

/* EN GPIO control */
void changeEN()
{
  switch (ENstatus) {
	case 0:
	  ENstatus = 1;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  clear7SEG();
	  display7SEG(1);
	  break;
	case 1:
	  ENstatus = 0;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	  clear7SEG();
	  display7SEG(2);
	  break;
	default:
	  break;
  }
}
