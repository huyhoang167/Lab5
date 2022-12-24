/*
 * global.h
 *
 *  Created on: Dec 24, 2022
 *      Author: Hoang
 */
#include "stdint.h"
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define WAITING_START 0
#define WAITING_END 1
#define WAITING_RTS 2
#define SEND_ADC 3
#define WAIT_OK 4
extern int command_status;
extern int uart_status;
#define MAX_BUFFER_SIZE 30
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

#endif /* INC_GLOBAL_H_ */
