/*
 * fsm.h
 *
 *  Created on: Dec 24, 2022
 *      Author: Hoang
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
void command_parser_fsm();
void uart_communiation_fsm(UART_HandleTypeDef huart2, ADC_HandleTypeDef hadc1);


#endif /* INC_FSM_H_ */