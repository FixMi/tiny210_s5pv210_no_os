#include "stdio.h"
#include "led.h"
#include "delay.h"
#include "sdio_sdcard.h"

void uart_init(void);

int main(void)
{
	int a = 0;
	int b = 0;
	char c;

	uart_init();
	led_init();
	system_initexception();		
	SD_Init();



	printf("SD Card test..\r\n");

	while (1)
	{
		led_set(LED1, ON);
		delay();
		led_set(LED1, OFF);
		delay();
	}

	return 0;
}
