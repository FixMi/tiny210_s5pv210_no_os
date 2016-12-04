#ifndef __LED_H
#define __LED_H

#define		GPJ2CON		(*(volatile unsigned long *) 0xE0200280)
#define		GPJ2DAT		(*(volatile unsigned long *) 0xE0200284)

#define		GPJ2_0_OUTPUT	(1<<(0*4))
#define		GPJ2_1_OUTPUT	(1<<(1*4))
#define		GPJ2_2_OUTPUT	(1<<(2*4))
#define		GPJ2_3_OUTPUT	(1<<(3*4))

typedef enum 
{
	LED1,
	LED2,
	LED3,
	LED4,
	LED_MAX
} LED;

typedef enum
{
	OFF = 0,
	ON = !OFF
} LED_STATUS;

void led_init(void);
void led_set(LED led, LED_STATUS onoff);

#endif
