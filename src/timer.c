/*
 * timer.c
 *
 *  Created on: Sep 17, 2014
 *      Author: caio
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../include/usart.h"

void TIMER_Init(void){
	 TCCR0A |= (1 << WGM01);		// Set the Timer Mode to CTC
	 OCR0A = 99; 	    			// Set the value that you want to count to 249
	 //TIMSK0 |= (1 << OCIE0A);    	// Set the ISR COMPA vect
	 TCCR0B |= (1 << CS01); 	    // set prescaler to 8 and start the timer
}

void TIMER_Start (void){
	TIMSK0 |= (1 << OCIE0A);
}
void TIMER_Stop (void){
	TIMSK0 &= ~(1 << OCIE0A);
}
