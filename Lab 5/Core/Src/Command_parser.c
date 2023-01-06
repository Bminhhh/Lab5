/*
 * Command_parser.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Lenovo
 */
#include "Command_parser.h"
#include "main.h"
#include "UART.h"
#include "global.h"

void command_praser_fsm(){
	switch(command_praser_fsm_case){
	case WAITING_FOR_CHAMTHAN_1:
			if(temp == '!')
			{
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
				command_praser_fsm_case = WAITING_FOR_R;
//				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
			}
			break;
		case WAITING_FOR_R:
			if(temp == 'R')
			{
				command_praser_fsm_case = WAITING_FOR_S;
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_1;
			}
			break;
		case WAITING_FOR_S:
			if(temp == 'S')
			{
				command_praser_fsm_case = WAITING_FOR_T;
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_1;
			}
			break;
		case WAITING_FOR_T:
			if(temp == 'T')
			{
				command_praser_fsm_case = WAITING_FOR_THANG_1;
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_1;
			}
			break;
		case WAITING_FOR_THANG_1:
			if(temp == '#')
			{
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
				uart_communiation_fsm_case = RST_DONE;
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_2;
				setTimer(10);
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_1;
			}
			break;
		//ok check
		case WAITING_FOR_CHAMTHAN_2:
			if(temp == '!')
			{
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
				command_praser_fsm_case = WAITING_FOR_O;
			}
			break;
		case WAITING_FOR_O:
			if(temp == 'O')
			{
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
				command_praser_fsm_case = WAITING_FOR_K;
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_2;
			}
			break;
		case WAITING_FOR_K:
			if(temp == 'K')
			{
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
				command_praser_fsm_case = WAITING_FOR_THANG_2;
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_2;
			}
			break;
		case WAITING_FOR_THANG_2:
			if(temp == '#')
			{
				HAL_GPIO_TogglePin(Yellow_GPIO_Port, Yellow_Pin);
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_1;
				uart_communiation_fsm_case = OK_DONE;
			}
			else
			{
				command_praser_fsm_case = WAITING_FOR_CHAMTHAN_2;
			}
			break;
		default:
			break;
	}
}

