/*
 * global.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Lenovo
 */
#include "global.h"
#include "UART.h"
#include "Command_parser.h"

int command_praser_fsm_case = WAITING_FOR_CHAMTHAN_1;
int buffer_flag = 0;
uint8_t temp = 0;
int uart_communiation_fsm_case = WAITING_FOR_RST;
