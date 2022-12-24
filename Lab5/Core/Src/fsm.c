/*
 * fsm.c
 *
 *  Created on: Dec 24, 2022
 *      Author: Hoang
 */
#include "fsm.h"
#include "string.h"
#include "global.h"
#include "software_timer.h"
#include "main.h"

char command[30];
char command_index = 0;
char command_done = 0;
int ADC_value = 0;
char str[30];
void command_parser_fsm(){
	switch(command_status){
		case WAITING_START:
			if (buffer[index_buffer-1] == '!'){
				command_status = WAITING_END;
				command_index = 0;
			}
			break;
		case WAITING_END:
			if (buffer[index_buffer-1] == '#'){
				command_status = WAITING_START;
				command[command_index] = '\0';
				command_done = 1;

			}
			else{
				command[command_index++] = buffer[index_buffer-1];
				if (command_index == 30) command_index = 0;
			}
			break;
		default:
			break;
	}
}
char * get_command(){
	return command;
}
void uart_communiation_fsm(UART_HandleTypeDef huart2, ADC_HandleTypeDef hadc1){
	switch(uart_status){
		case WAITING_RTS:
			if (command_done == 1){
				command_done = 0;
				//HAL_GPIO_TogglePin ( LED_RED_GPIO_Port , LED_RED_Pin );
				if (strcmp(get_command(), "RTS") == 0){
				//HAL_UART_Transmit (huart , ( void *) str , sprintf ( str ,"%d\n",ADC_value),1000) ;
					ADC_value = HAL_ADC_GetValue(&hadc1);
					uart_status = SEND_ADC;
					setTimer2(3000);
					HAL_UART_Transmit (&huart2,( void *) str , sprintf( str,"\r\n"),1000);
				}
			}
			break;
		case SEND_ADC:
			HAL_UART_Transmit (&huart2,( void *) str , sprintf( str,"!ADC=%d#\r\n",ADC_value),1000);
			uart_status = WAIT_OK;
			break;
		case WAIT_OK:
			if (command_done == 1){
				command_done = 0;
				if (strcmp(get_command(),"OK") == 0){
					uart_status = WAITING_RTS;
					HAL_UART_Transmit (&huart2,( void *) str , sprintf( str,"\r\n"),1000);
					Stop_timer();
				}
			}
			if (timer2_flag == 1){
				uart_status = SEND_ADC;
				setTimer2(3000);
			}
			break;
		default:
			break;
	}
}

