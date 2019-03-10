#include "conf.h"
#include "api.h"


#include "avr-api/api.h"


Platform * pl;
Wheel * wh;

int main()
{
	wh = (WheelDynamicSpeed*)malloc(sizeof(WheelDynamicSpeed));
	wh->setStatus(1);
	((WheelDynamicSpeed*)wh)->setSpeed(1);
	pinMode(15, OUTPUT);
	sei();
	//pl = new Platform(TEMPLATE_4WH_2ALONG_2PERP);
	pl->addWheel(wh);
	USART0Begin(115200);
	sei();
	while(1)
	{
		USART0Println("AAA");
		_delay_ms(100);
	}
	return 0;
}
