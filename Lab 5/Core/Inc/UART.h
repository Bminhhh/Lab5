/*
 * UART.h
 *
 *  Created on: Dec 4, 2022
 *      Author: Lenovo
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
#include "Command_parser.h"
#include "timer.h"


extern char str[50];
extern uint32_t ADC_value;

void UART_communication_run();

#endif /* INC_UART_H_ */
