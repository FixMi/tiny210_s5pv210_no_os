#include "led.h"
#include "delay.h"

void main(void)
{
	led_init();

	while (1)
	{
		led_set(LED1, ON);
		delay();
		led_set(LED1, OFF);
		delay();
	}

}


