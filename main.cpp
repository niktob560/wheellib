#include "conf.h"
#include "api.h"

Platform * pl;

int main()
{
	pl = (Platform*)malloc(sizeof(Platform));
	USART0Begin(115200);
	sei();
	while(1)
	{
		USART0Println("AAA");
		USART0Send('\r');
		_delay_ms(100);
	}
	return 0;
}
