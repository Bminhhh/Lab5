/*
 * UART.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Lenovo
 */
#include "main.h"
#include "timer.h"
#include "UART.h"
#include "global.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

uint32_t ADC_value = 0;
char str[100];
void uart_communiation_fsm()
{
	switch(uart_communiation_fsm_case)
	{
		case WAITING_FOR_RST:
			//donothing
			break;
		case RST_DONE:
			if(timer_flag == 1)
			{
				setTimer(150);
				ADC_value = HAL_ADC_GetValue (&hadc1);
				HAL_UART_Transmit(&huart2,(void*)str ,sprintf (str,"!ADC = %d# \n",ADC_value),1000);
			}
			break;
		case OK_DONE:
			uart_communiation_fsm_case = WAITING_FOR_RST;
			break;
		default:
			break;
	}
}
