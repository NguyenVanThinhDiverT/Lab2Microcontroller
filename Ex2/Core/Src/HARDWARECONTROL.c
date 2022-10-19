/*
 * HARDWARECONTROL.c
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */

#include "HARDWARECONTROL.h"

void initGPIO()
{
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, 1);
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
                           SEG3_Pin | SEG4_Pin | SEG5_Pin |
						   SEG6_Pin, 1);
}
