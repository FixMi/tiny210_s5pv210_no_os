#include "stdio.h"
#include "led.h"
#include "delay.h"
#include "sdio_sdcard.h"

void uart_init(void);

char write_buffer[] = "hello SD Card test....";
char read_buffer[2048] = {0};

int main(void)
{
	int a = 0;
	int b = 0;
	char c;
	int ret = 0;
	int start_block, end_block;

	uart_init();
	led_init();
	system_initexception();		

	printf("\r\nSD Card test..\r\n");

	sd_init();

	//擦除命令无效
	//写失败
	//读取成功

	start_block = 500;
	end_block = 510;

	printf("erase SD card, blocks: [%d, %d]...\r\n", start_block, end_block);
	sd_erase_block(start_block, end_block);
	printf("write SD card, start block: %d\r\n", start_block);
	ret = sd_write_block(write_buffer, start_block, 1);
	printf("write ret: %d\r\n", ret);	
//	printf("read SD card, block: \r\n", start_block);
//	sd_read_block(read_buffer, start_block, 1);
//	printf("read data: %s\r\n", read_buffer);


	while (1)
	{
		led_set(LED1, ON);
		delay();
		led_set(LED1, OFF);
		delay();
	}

	return 0;
}
