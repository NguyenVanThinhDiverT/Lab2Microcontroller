/*
 * SOFTWARETIMER.c
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */

#include "SOFTWARETIMER.h"

int EN_counter = 0;
int LED_counter = 0;
int timer1_counter = 0;
int EN_flag = 0;
int LED_flag = 0;
int timer1_flag = 0;
void setTimer_EN(int duration){
	EN_counter = duration;
	EN_flag = 0;
}
void setTimer_LED(int duration){
	LED_counter = duration;
	LED_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}
void timerRun(){
	if(EN_counter > 0){
		EN_counter--;
		if(EN_counter <= 0){
			EN_flag = 1;
		}
	}
	if(LED_counter > 0){
		LED_counter--;
		if(LED_counter <= 0){
			LED_flag = 1;
		}
	}
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}
