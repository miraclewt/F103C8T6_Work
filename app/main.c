/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 * Change Logs:
 * Date           Author       Notes
 * 2024-03-26     LCKFB-LP    first version
 */
#include "stm32f10x.h"
#include "board.h"
#include "bsp_uart.h"
#include "stdio.h"

int main(void)
{
	
	board_init();
	
	uart1_init(115200);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);

	
	while(1)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		printf("LED ON!\r\n");
		delay_ms(500);
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		printf("LED OFF!\r\n");
		delay_ms(500);
		
		uint8_t *t = uart1_get_data();
		if(t != NULL)
		{
			printf("data = %s\r\n",t);
		}
	}
	
}
