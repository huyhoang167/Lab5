/*
 * global.c
 *
 *  Created on: Dec 24, 2022
 *      Author: Hoang
 */

#include "global.h"
int command_status = WAITING_START;
int uart_status = WAITING_RTS;
uint8_t temp = 0;
uint8_t buffer [MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
