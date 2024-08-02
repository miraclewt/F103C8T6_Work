#include "stm32f10x.h"
#include "board.h"
#include "bsp_uart.h"
#include "stdio.h"
#include "oled.h"

int main(void)
{
	
	board_init();
	
	uart1_init(115200);
	OLED_Init();
	OLED_Clear();

	
	while(1)
	{
	OLED_ShowString(0,0,(uint8_t *)"ABC",8,1);//6*8 “ABC”
	OLED_ShowString(0,8,(uint8_t *)"ABC",12,1);//6*12 “ABC”
	OLED_ShowString(0,20,(uint8_t *)"ABC",16,1);//8*16 “ABC”
	OLED_ShowString(0,36,(uint8_t *)"DEF",24,1);//12*24 “ABC”
	OLED_Refresh();
	delay_ms(100);
	}
	
}
