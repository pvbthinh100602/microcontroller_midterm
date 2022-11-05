/*
 * fsm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: phamv
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "global.h"
#include "display.h"

#define TIME_OUT 10000

void fsm_simple_button_run(void);
void fsm_long_pressed_button_run(void);
void fsm_no_pressed_button_run(void);

#endif /* INC_FSM_H_ */
