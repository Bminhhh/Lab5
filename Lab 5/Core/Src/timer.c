/*
 * timer.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Lenovo
 */


#include "timer.h"
#include "main.h"

int timer_flag;
int counter;
void setTimer(int duration){
	counter = duration;
	timer_flag = 0;
}
void timerRun(){
	if(counter > 0){
		counter --;
	}
	if(counter <= 0){
		timer_flag = 1;
	}
}
