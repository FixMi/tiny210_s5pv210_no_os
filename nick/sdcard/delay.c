#include "delay.h"




void delay(void)
{
	volatile int i = 0x100000;

	while (i--)
		;
}



void delay_us(unsigned int nCount)
{
   __asm__ __volatile__(
     "000:\n"
      "ldr r1,=250\n"
     "111:\n"
     "subs r1,r1,#1\n"       //one arm clock
     "bne 111b\n"            //three arm clock
     "subs r0,r0,#1\n"
     "bne 000b\n"            //three arm clock
   );
}








