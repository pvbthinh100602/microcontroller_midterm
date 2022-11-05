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
		reset7SEG();
		status = NOR_PRESSED;
		setTimer1(TIME_OUT);
		break;
	case NOR_PRESSED:
		if(timer1_flag){
			status = AUTO_DEC;
			setTimer2(250);
			if(counter != 0) {
				decrease7SEG();
				setTimer1(1000);
			}
		}

		if(isButtonPressed(0)){
			toggleRed();
			reset7SEG();
			setTimer1(TIME_OUT);
		}

		if(isButtonPressed(1)){
			toggleRed();
			increase7SEG();
			setTimer1(TIME_OUT);
		}

		if(isButtonPressed(2)){
			toggleRed();
			decrease7SEG();
			setTimer1(TIME_OUT);
		}

		if(isButtonLongPressed(1)){
			status = LONG_INC;
			setTimer2(250);
		}

		if(isButtonLongPressed(2)){
			status = LONG_DEC;
			setTimer2(250);
		}
		break;
	default:
		break;
	}
}

void fsm_long_pressed_button_run(void){
	switch(status){
	case LONG_INC:
		if(timer2_flag){
			toggleRed();
			setTimer2(500);
		}
		if(isButtonPressed(1)){
			increase7SEG();
		}
		if(isButtonLongPressed(1) == 0){
			status = NOR_PRESSED;
			setTimer1(TIME_OUT);
		}
		break;
	case LONG_DEC:
		if(timer2_flag){
			toggleRed();
			setTimer2(500);
		}
		if(isButtonPressed(2)){
			decrease7SEG();
		}
		if(isButtonLongPressed(2) == 0){
			status = NOR_PRESSED;
			setTimer1(TIME_OUT);
		}
		break;
	}
}

void fsm_no_pressed_button_run(void){
	switch(status){
	case AUTO_DEC:
		if(timer2_flag){
			toggleRed();
			setTimer2(1000);
		}
		if(timer1_flag){
			if(counter != 0) {
				decrease7SEG();
				setTimer1(1000);
			}
		}
		if(isButtonPressed(0)){
			status = NOR_PRESSED;
			reset7SEG();
			setTimer1(TIME_OUT);
		}
		if(isButtonPressed(1)){
			status = NOR_PRESSED;
			increase7SEG();
			setTimer1(TIME_OUT);
		}
		if(isButtonPressed(2)){
			status = NOR_PRESSED;
			decrease7SEG();
			setTimer1(TIME_OUT);
		}
		break;
	default:
		break;
	}
}
