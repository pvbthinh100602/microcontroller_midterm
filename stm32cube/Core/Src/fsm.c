/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: phamv
 */

#include "fsm.h"

void fsm_simple_button_run(void){
	switch(status){
	case INIT:
		counter = 0;
		display7SEG();
		status = SIMPLE_PRESSED;
		break;
	case SIMPLE_PRESSED:
		if(isButtonPressed(0)){
			counter = 0;
			display7SEG();
		}

		if(isButtonPressed(1)){
			increase7SEG();
			if(isButtonLongPressed(1)){
				status = LONG_INC;
			}
		}

		if(isButtonPressed(2)){
			decrease7SEG();
			if(isButtonLongPressed(2)){
				status = LONG_DEC;
			}
		}
		break;
	default:
		break;
	}
}

void fsm_long_pressed_button_run(void){
	switch(status){
	case LONG_INC:
		if(isButtonPressed(1)){
			increase7SEG();
		}
		if(isButtonLongPressed(1) == 0){
			status = SIMPLE_PRESSED;
		}
		break;
	case LONG_DEC:
		if(isButtonPressed(2)){
			decrease7SEG();
		}
		if(isButtonLongPressed(2) == 0){
			status = SIMPLE_PRESSED;
		}
		break;
	}
}
