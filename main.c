
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"
#include <util/delay.h>


int main (void)
{

DDRD=0xff;

init_UART();

   while(1)
   {

	   UART_SEND_string("ahmed saleh nmr \r\n");
	   UART_SEND_string("Embeddedfab\r\n");
	   UART_SEND_string("Allah akber \r\n");

	   UART_SEND_string("\r\n");
	   PORTD=0xff;
	_delay_ms(1000);

   }
   return 0;
}



