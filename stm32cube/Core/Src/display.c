/*
 * display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: phamv
 */

#include "display.h"

void display7SEG(int num){
	HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin|LED7SEG_B_Pin|LED7SEG_C_Pin|LED7SEG_D_Pin
							|LED7SEG_E_Pin|LED7SEG_F_Pin|LED7SEG_G_Pin, GPIO_PIN_SET);
	switch(num){
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
