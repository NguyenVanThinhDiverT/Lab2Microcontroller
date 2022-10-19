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
int led_buffer [4] = {1 , 2 , 3 , 4};

/* clock variable */
int hour = 7, minute = 59, second = 50;

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

void initState(){
	ENstatus = 0;
}
void openEN(int state){
	if(state == 0){
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
	}
	if(state == 1){
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
	}
	if(state == 2){
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, 0);
	}
	if(state == 3){
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, 0);
	}
}
void clearEN(){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);
}

void displayClock(int hour, int minute){
	if(ENstatus == 0){
		clearEN();
		clear7SEG();
		openEN(ENstatus);
		display7SEG(hour / 10);
		ENstatus++;
	}
	else if(ENstatus == 1){
		clearEN();
		clear7SEG();
		openEN(ENstatus);
		display7SEG(hour % 10);
		ENstatus++;
	}
	else if(ENstatus == 2){
		clearEN();
		clear7SEG();
		openEN(ENstatus);
		display7SEG(minute / 10);
		ENstatus++;
	}
	else{
		clearEN();
		clear7SEG();
		openEN(ENstatus);
		display7SEG(minute % 10);
		ENstatus = 0;
	}
}

/* Blink Led */
void blinkLED(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
}

/* display buffer */
void update7SEG(int index){
	switch(index){
		case 0:
			// Display the first 7 SEG with led_buffer [0]
			clear7SEG();
			clearEN();
			openEN(index);
			display7SEG(led_buffer[index]);
			break ;
		case 1:
			// Display the second 7 SEG with led_buffer [1]
			clear7SEG();
			clearEN();
			openEN(index);
			display7SEG(led_buffer[index]);
			break ;
		case 2:
			// Display the third 7 SEG with led_buffer [2]
			clear7SEG();
			clearEN();
			openEN(index);
			display7SEG(led_buffer[index]);
			break ;
		case 3:
			// Display the forth 7 SEG with led_buffer [3]
			clear7SEG();
			clearEN();
			openEN(index);
			display7SEG(led_buffer[index]);
			break ;
		default :
			break ;
	}
}

/* update buffer */
void updateClockBuffer(){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}

