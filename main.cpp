#include <avr/io.h>                     //include for base avr funcs
#define F_CPU 16000000          //define with freq
#include <util/delay.h>                 //include for delay func
#include <avr/interrupt.h>      //include interrupt funcs
#include <stdlib.h>

#define NUM_OF_ANALOG_PINS 7
#define USE_ADC 1

//---------TIMERS----------
#define USE_TIMERS 1

//---------USART----------
#define USE_USART 1
#define USE_USART0 1
#define USE_USART0_OUTPUT 1
#define USE_USART0_INPUT 1
#define USE_SERIAL_FASTBAUD 0

//---------CUSTOM_INTERRUPTS----------
#define USE_CUSTOM_INTERRUPTS 1

#include "avr-api/api.h"


int main()
{
	USART0Begin(115200);
	sei();
	while(1)
	{
		USART0Println("AAA");
		USART0Send('\r');
		_delay_ms(100);
	}
}
