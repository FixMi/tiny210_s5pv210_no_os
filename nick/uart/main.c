#include "stdio.h"
#include "led.h"
#include "delay.h"

void uart_init(void);

int main(void)
{
	int a = 0;
	int b = 0;
	char c;

	uart_init();
	led_init();

	printf("hello nick\r\n");

	while (1)
	{
		led_set(LED1, ON);
		delay();
		led_set(LED1, OFF);
		delay();
	}

	return 0;
}
