/*
 * SOFTWARETIMER.h
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int EN_flag;
extern int LED_flag;
extern int timer1_flag;
void setTimer_EN(int duration);
void setTimer_LED(int duration);
void setTimer1(int duration);
void timerRun();


#endif /* INC_SOFTWARETIMER_H_ */
