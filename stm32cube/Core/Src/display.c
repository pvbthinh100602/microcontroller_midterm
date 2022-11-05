/*
 * display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: phamv
 */

#include "display.h"

void display7SEG(void){
	HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin
							|LED7SEG_E_Pin|LED7SEG_F_Pin|LED7SEG_G_Pin, GPIO_PIN_SET);
	switch(counter){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin
								|LED7SEG_E_Pin|LED7SEG_F_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_B_Pin|LED7SEG_C_Pin, GPIO_PIN_RESET);
	break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_D_Pin|LED7SEG_E_Pin
								|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin
								|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_F_Pin|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin|LED7SEG_F_Pin
								|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin|LED7SEG_E_Pin
								|LED7SEG_F_Pin|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin
								|LED7SEG_E_Pin|LED7SEG_F_Pin|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin
								|LED7SEG_F_Pin|LED7SEG_G_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}

void increase7SEG(void){
	counter++;
	if(counter > 9) counter = 0;
	display7SEG();
}

void decrease7SEG(void){
	counter--;
	if(counter < 0) counter = 9;
	display7SEG();
}
