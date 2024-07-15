/*
 * ������������Ӳ�������������չ����Ӳ�����Ϲ���ȫ����Դ
 * �����������www.lckfb.com
 * ����֧�ֳ�פ��̳���κμ������⻶ӭ��ʱ����ѧϰ
 * ������̳��https://oshwhub.com/forum
 * ��עbilibili�˺ţ������������塿���������ǵ����¶�̬��
 * ��������׬Ǯ���������й�����ʦΪ����
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
