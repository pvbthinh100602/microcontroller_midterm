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
		display7SEG(0);
		status = SIMPLE_PRESSED;
		break;
	case SIMPLE_PRESSED:
		if(isButtonPressed(0)){
			counter = 0;
			display7SEG(counter);
		}

		if(isButtonPressed(1)){
			counter++;
			if(counter > 9) counter = 0;
			display7SEG(counter);
		}

		if(isButtonPressed(2)){
			counter--;
			if(counter < 0) counter = 9;
			display7SEG(counter);
		}
		break;
	default:
		break;
	}
}
