/*
 * LED.c
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */

#include "LED.h"

int ENstatus = 0; //Enable GPIO state

/* buffer variable */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1 , 2 , 3 , 4};
//int led_buffer[4] = {5 , 7 , 9 , 4};

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
  HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin | DOT_Pin);
}

/* EN GPIO control */
void changeEN()
{
  switch (ENstatus) {
	case 0:
	  ENstatus = 1;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  clear7SEG();
	  display7SEG(led_buffer[0]);
	  break;
	case 1:
	  ENstatus = 2;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  clear7SEG();
	  display7SEG(led_buffer[1]);
	  break;
	case 2:
	  ENstatus = 3;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  clear7SEG();
	  display7SEG(led_buffer[2]);
	  break;
	case 3:
	  ENstatus = 0;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	  clear7SEG();
	  display7SEG(led_buffer[3]);
	  break;
	default:
	  break;
  }
}
/* display buffer */
void update7SEG(int index)
{
  switch (index)
  {
	case 0:
	  changeEN();
	  break;
	case 1:
	  changeEN();
	  break;
	case 2:
	  changeEN();
	  break;
	case 3:
      changeEN();
	  break;
	default:
	  break;
  }
}
