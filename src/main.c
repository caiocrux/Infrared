/*
 * main.c
 *
 *  Created on: Jul 29, 2014
 *      Author: caio
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../include/usart.h"
#include "../include/timer.h"
#include "../include/interrupt.h"

int main (void){
	DDRB = (1<<PB3); //make Arduino Pin 11 as output
	DDRB = (1<<PB4); //make Arduino Pin 12 as output

	USART_Init(57600);
	TIMER_Init();
	INT_Init();
	//IRReciverInit();
	sei(); // Enable the Service Interrupt Routine

	while (1){
		 // Put the code here
	}
	return 0;
}

