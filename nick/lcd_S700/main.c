#include "stdio.h"
#include "lcd.h"

#define WIDTHEIGHT	800
#define HEIGHT	480

void uart_init(void);

int main(void)
{
	int c = 0;

	// 初始化串口
	uart_init();

	// 初始化LCD
	lcd_init();

	lcd_clear_screen(0x000000);

//	lcd_draw_pixel(0, 0, 0x00ff00);


	lcd_draw_cross(240, 400, 200, 0x0000ff);

	// 打印菜单
	while(1)
	{
		printf("\r\n###############LCD Test##############\r\n");
		printf("[1] lcd_clear_screen\r\n");
		printf("[2] lcd_draw_cross\r\n");
		printf("[3] lcd_draw_hline\r\n");
		printf("[4] lcd_draw_vline\r\n");
		printf("[5] lcd_draw_circle\r\n");
		printf("Enter your choice:");
		c = getc();
		printf("%c\r\n",c);
		switch(c)
		{
			case '1':
				// 清屏
				lcd_clear_screen(0x000000);									// 黑
				break;
			case '2':
				// 划十字
				lcd_draw_cross(50, 50, 20, 0x0000ff);						// 蓝
				break;
			case '3':
				// 划横线
				lcd_draw_hline(HEIGHT/2, 100, WIDTHEIGHT-100, 0xff0000);	// 红
				break;
			case '4':
				// 划竖线
				lcd_draw_vline(WIDTHEIGHT/2, 50, HEIGHT-50, 0x00ff00);		// 绿
				break;
			case '5':
				lcd_draw_pixel(0, 0, 0x00ff00);
				break;
			default:
				break;
		}
	}
	return 0;
}
