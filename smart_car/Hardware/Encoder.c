#include "stm32f10x.h"
void Encoder_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_IPU;
	G.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &G);
	TIM_TimeBaseInitTypeDef T;
	T.TIM_ClockDivision = TIM_CKD_DIV1;
	T.TIM_CounterMode = TIM_CounterMode_Up;
	T.TIM_Period = 65535;
	T.TIM_Prescaler = 0;
	T.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &T);
	TIM_ICInitTypeDef I;
	TIM_ICStructInit(&I);
	I.TIM_Channel = TIM_Channel_1;
	I.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM3, &I);
	I.TIM_Channel = TIM_Channel_2;
	TIM_ICInit(TIM3, &I);
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12,
		TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_SetCounter(TIM3, 32768);
	TIM_Cmd(TIM3, ENABLE);
}
int16_t Encoder_GetDelta(void)
{
	int16_t d = (int16_t)(TIM_GetCounter(TIM3) - 32768);
	TIM_SetCounter(TIM3, 32768);
	return d;
}
