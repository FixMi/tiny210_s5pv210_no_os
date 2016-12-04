#include "led.h"

void led_init(void)
{
	GPJ2CON = GPJ2_0_OUTPUT | GPJ2_1_OUTPUT | GPJ2_2_OUTPUT | GPJ2_3_OUTPUT;
	GPJ2DAT |= 1 << 0;
	GPJ2DAT |= 1 << 1;
	GPJ2DAT |= 1 << 2;
	GPJ2DAT |= 1 << 3;
}

void led_set(LED led, LED_STATUS onoff)
{
	if (onoff)
	{
		GPJ2DAT &= ~(1 << led);
	}
	else
	{
		GPJ2DAT |= (1 << led);
	}
}



