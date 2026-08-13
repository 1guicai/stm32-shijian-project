#include "stm32f10x.h"
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_Out_PP;
	G.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &G);
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}
void LED1_ON(void)  { GPIO_ResetBits(GPIOA, GPIO_Pin_1); }
void LED1_OFF(void) { GPIO_SetBits(GPIOA, GPIO_Pin_1); }
void LED1_Turn(void){ GPIO_WriteBit(GPIOA, GPIO_Pin_1,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1))); }
void LED2_ON(void)  { GPIO_ResetBits(GPIOA, GPIO_Pin_2); }
void LED2_OFF(void) { GPIO_SetBits(GPIOA, GPIO_Pin_2); }
void LED2_Turn(void){ GPIO_WriteBit(GPIOA, GPIO_Pin_2,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2))); }
