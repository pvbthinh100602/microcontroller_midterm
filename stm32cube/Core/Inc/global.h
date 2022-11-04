/*
 * global.h
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"

#define INIT		1

#define AUTO_RED1	2
#define AUTO_RED2	3
#define AUTO_GREEN	4
#define AUTO_YELLOW 5

#define MAN_RED 	11
#define MAN_GREEN	12
#define MAN_YELLOW	13

#define BLINKY_TIME	500

extern int status;

extern int config_red;
extern int config_green;
extern int config_yellow;

extern int counter_red;
extern int counter_green;
extern int counter_yellow;

#endif /* INC_GLOBAL_H_ */
