/*
 * button.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */
#include "button.h"

static int button_buffer[NO_OF_BUTTONS];

static int debounce_buffer1[NO_OF_BUTTONS];
static int debounce_buffer2[NO_OF_BUTTONS];
static int debounce_buffer3[NO_OF_BUTTONS];

static int button_state[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};

static int counter_for_button_pressed[NO_OF_BUTTONS];

static int button_flag[NO_OF_BUTTONS];

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void button_process(int index){
	if(index >= 0 && index < NO_OF_BUTTONS){
		button_flag[index] = 1;
	}
}

void button_reading(){
	for(uint8_t i = 0 ; i < NO_OF_BUTTONS; i++){
        //debouncing button
		debounce_buffer3[i] = debounce_buffer2[i];
		debounce_buffer2[i] = debounce_buffer1[i];
		uint16_t button_pin = 0;
		switch(i){
		case 0:
			button_pin = BUTTON0_Pin;
			break;
		case 1:
			button_pin = BUTTON1_Pin;
			break;
		case 2:
			button_pin = BUTTON2_Pin;
			break;
		default:
			break;
		}
		debounce_buffer1[i] = HAL_GPIO_ReadPin(GPIOA, button_pin);
        process after debouncing
		if((debounce_buffer3[i] == debounce_buffer2[i]) && debounce_buffer2[i] == debounce_buffer1[i]){
			button_buffer[i] = debounce_buffer3[i];
			// fsm for processing button
			switch(button_state[i]){
			case BUTTON_IS_PRESSED:
		        //waiting for a period if the button is pressed in a duration
				counter_for_button_pressed[i]++;
				if(counter_for_button_pressed[i] == WAITING_TIME/TIMER_CYCLE){
					button_state[i] = BUTTON_IS_PRESSED_IN_PERIOD;
					counter_for_button_pressed[i] = 0;
					button_process(i);
				}
				if(button_buffer[i] == RELEASED_STATE){
					button_state[i] = BUTTON_IS_RELEASED;
					counter_for_button_pressed[i] = 0;
				}
				break;
			case BUTTON_IS_RELEASED:
				if(button_buffer[i] == PRESSED_STATE){
					button_state[i] = BUTTON_IS_PRESSED;
					button_process(i);
				}
				break;
			case BUTTON_IS_PRESSED_IN_PERIOD:
	            //if the button continues being pressed in duration, the button only triggered in a period defined previous.
				counter_for_button_pressed[i]++;
				if(counter_for_button_pressed[i] == TIME_OUT_FOR_KEY_PRESSED/TIMER_CYCLE){
					button_process(i);
					counter_for_button_pressed[i] = 0;
				}
				if(button_buffer[i] == RELEASED_STATE){
					button_state[i] = BUTTON_IS_RELEASED;
					counter_for_button_pressed[i] = 0;
				}
				break;
			default:
				break;
			}
		}
	}
}


