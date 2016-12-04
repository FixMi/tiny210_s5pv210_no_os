#include "delay.h"




void delay(void)
{
	volatile int i = 0x100000;

	while (i--)
		;
}
