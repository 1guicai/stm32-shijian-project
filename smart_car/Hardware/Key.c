#include "stm32f10x.h"
#include "Delay.h"
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_IPU;
	G.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &G);
}
uint8_t Key_GetNum(void)
{
	static uint8_t L1=1, L2=1;
	uint8_t Kn=0;
	uint8_t C1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
	uint8_t C2 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	if(L1==0 && C1==1){ Delay_ms(20); Kn=1; }
	if(L2==0 && C2==1){ Delay_ms(20); Kn=2; }
	L1=C1; L2=C2; return Kn;
}
