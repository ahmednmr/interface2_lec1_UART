
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"
#include <util/delay.h>

#define CHECK_SEND   1
#define CHECK_REC    0


#if CHECK_SEND


int main (void)
{
	init_UART();
	while(1)
	{
		UART_SEND_string("Hello from \r\n");
		UART_SEND_string("Embedded fab\r\n");
		UART_SEND_string("\r\n");

		_delay_ms(1000);
	}
	return 0;
}


#endif


#if CHECK_REC

int main (void)
{

	char x;
	DDRD=0xff;

	init_UART();
	UART_SEND_string("start Prog\r\n");

	while(1)
	{

		x=UART_getChar();
		if(x=='7')
		{
			PORTD=0x00;
			PORTD|=(1<<PD7);
			UART_SEND_string("Done turning on SW 7\r\n");
		}
		else if(x=='6')
		{
			PORTD=0x00;
			PORTD|=(1<<PD6);
			UART_SEND_string("Done turning on SW 6\r\n");
		}
		else if(x=='5')
		{
			PORTD=0x00;
			PORTD|=(1<<PD5);
			UART_SEND_string("Done turning on SW 5\r\n");
		}
		else if(x=='4')
		{
			PORTD=0x00;
			PORTD|=(1<<PD4);
			UART_SEND_string("Done turning on SW 4\r\n");
		}



		_delay_ms(1000);

	}
	return 0;
}

#endif


