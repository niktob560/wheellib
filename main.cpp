#include "conf.h"
#include "api.h"





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
