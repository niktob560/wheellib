#include "conf.h"
#include "api.h"


#include "avr-api/api.h"


Platform * pl;
Wheel * wh;

int main()
{
	pinMode(15, OUTPUT);
	sei();
	//pl = new Platform(TEMPLATE_4WH_2ALONG_2PERP);
	//pl->addWheel(new Wheel());
	USART0Begin(115200);
	sei();
	while(1)
	{
		USART0Println("AAA");
		_delay_ms(100);
	}
	return 0;
}
