/*
 * SOFTWARETIMER.c
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */
#include "SOFTWARETIMER.h"

int clock_flag = 0;
int clock_timer = 0;

void setTimer(int duration)
{
	clock_timer = duration / 10;
	clock_flag = 0;
}

void timerRun()
{
	if(clock_timer > 0)
	{
		clock_timer--;
		if(clock_timer <= 0)
		{
			clock_timer = 0;
			clock_flag = 1;
		}
	}
}

