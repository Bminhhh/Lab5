/*
 * global.h
 *
 *  Created on: Dec 4, 2022
 *      Author: Lenovo
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "command_parser.h"
#include "stdint.h"
#include "main.h"
#include "timer.h"
#include "UART.h"

#define MAX_BUFFER_SIZE 30

//command fsm case
#define WAITING_FOR_CHAMTHAN_1	6
#define WAITING_FOR_R			1
#define WAITING_FOR_S			2
#define WAITING_FOR_T			3
#define WAITING_FOR_THANG_1		7

#define WAITING_FOR_CHAMTHAN_2	8
#define WAITING_FOR_O			4
#define WAITING_FOR_K			5
#define WAITING_FOR_THANG_2		9

//uart_communiation_fsm_case
#define WAITING_FOR_RST			11
#define OK_DONE					12
#define RST_DONE				13


extern int command_praser_fsm_case;
extern int uart_communiation_fsm_case;
extern int buffer_flag ;
extern uint8_t temp ;


#endif /* INC_GLOBAL_H_ */
