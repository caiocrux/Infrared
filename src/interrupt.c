/*
 * reciver.c
 *
 *  Created on: Jul 29, 2014
 *      Author: caio
 */
#include <avr/interrupt.h>
#include <stdio.h>
#include "../include/interrupt.h"
#include "../include/usart.h"
#include "../include/timer.h"
int TIMER_counter = 0;

void INT_Init(void){
	DDRD &= ~(1 << PD2);       // Clear the PD2 pin make as an input.
	PORTD |= (1 << PORTD2);    // turn ON the Pull-up
    EICRA |= (1 << ISC00);     // set INT0 to trigger on ANY logic change
    EIMSK |= (1 << INT0);      // Turns on INT0
}
/* interrupt code here */
ISR(INT0_vect){
	char pin = PIND & (1 << PIND2);

	if( pin == 4 ) /* LOW to HIGH pin change */
	    {
			//USART_SendString("L-H\r\n");
			TIMER_Start();
	    }
	else /* HIGH to LOW pin change */
	    {
	    	//USART_SendString("H-L\r\n");
	    	TIMER_Stop();
	    	TIMER_counter--;
	    	TIMER_counter = TIMER_counter*5;

	        USART_SendInterger(TIMER_counter);
	    	TIMER_counter=0;
	    }

}
//event to be executed every 50us here
ISR(TIMER0_COMPA_vect){
	TIMER_counter++;
	PORTB ^= _BV(PB4);
}
