/*
 * LED.c
 *
 *  Created on: Oct 19, 2022
 *      Author: WELCOME
 */

#include "LED.h"

/*Code for 7 SEGMENT LED */
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
/* END CODE */

/* Code for blink LED */
void blinkLED(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
}
/* END CODE */

/* LED matrix animation - Characters shift left */
  /* Init variable */
  const int MAX_LED_MATRIX = 8;
  int index_led_matrix = 0;
  uint8_t matrix_buffer[MAX] = {0x00, 0xff, 0xff, 0x18, 0x18, 0xff, 0xff, 0x00, // H
    0x00, 0x00, 0xff, 0x11, 0x11, 0x0e, 0x00, 0x00, // P
    0x00, 0x00, 0xff, 0x11, 0x11, 0x0e, 0x00, 0x00, // P
	0x00, 0xff, 0x81, 0x81, 0x81, 0x42, 0x3c, 0x00}; // D
	// HPPD
  /* Function get buffer to GPIO */
  void getBuffer(uint8_t config)
  {
    HAL_GPIO_WritePin(GPIOB, ROW0_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW1_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW3_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW4_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW5_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW6_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW7_Pin, !(config&1));
  }

  /* Fuction for open ENM GPIO */
  void openENM(int index)
  {
	switch(index)
	{
	case 0:
	  HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 0);
	  break;
	case 1:
	  HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 0);
	  break;
	case 2:
	  HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 0);
	  break;
	case 3:
	  HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 0);
	  break;
	case 4:
	  HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 0);
	  break;
	case 5:
	  HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 0);
	  break;
	case 6:
	  HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 0);
	  break;
	case 7:
	  HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 0);
	  break;
	default:
	  break;
	}
  }

  /*Function for clear ENM GPIO */
  void clearENM()
  {
	  HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin |
                               ENM3_Pin | ENM4_Pin | ENM5_Pin |
							   ENM6_Pin | ENM7_Pin, 1);
  }

  /* Function update LED matrix */
  void updateLEDMatrix(int index)
  {
    switch(index)
    {
    case 0:
      getBuffer(matrix_buffer[index]);
      break;
    case 1:
	  getBuffer(matrix_buffer[index]);
      break;
    case 2:
        getBuffer(matrix_buffer[index]);
      break;
    case 3:
        getBuffer(matrix_buffer[index]);
      break;
    case 4:
        getBuffer(matrix_buffer[index]);
      break;
    case 5:
        getBuffer(matrix_buffer[index]);
      break;
    case 6:
        getBuffer(matrix_buffer[index]);
      break;
    case 7:
        getBuffer(matrix_buffer[index]);
      break;
    default:
      break;
    }
  }

  /* Function to shift left buffer */
  void shiftLeft()
  {
	uint8_t tmp = matrix_buffer[0];
	for(int i = 0; i < MAX; i++)
	{
	  if(i == MAX - 1) matrix_buffer[i] = tmp;
	  else matrix_buffer[i] = matrix_buffer[i + 1];
	}
  }
