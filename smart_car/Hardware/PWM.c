#include "stm32f10x.h"
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_AF_PP;
	G.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &G);
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseInitTypeDef T;
	T.TIM_ClockDivision = TIM_CKD_DIV1;
	T.TIM_CounterMode = TIM_CounterMode_Up;
	T.TIM_Period = 20000 - 1;
	T.TIM_Prescaler = 72 - 1;
	T.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &T);
	TIM_OCInitTypeDef O;
	TIM_OCStructInit(&O);
	O.TIM_OCMode = TIM_OCMode_PWM1;
	O.TIM_OCPolarity = TIM_OCPolarity_High;
	O.TIM_OutputState = TIM_OutputState_Enable;
	O.TIM_Pulse = 0;
	TIM_OC2Init(TIM2, &O);
	TIM_OC3Init(TIM2, &O);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_Cmd(TIM2, ENABLE);
}
void PWM_SetCompare2(uint16_t C){ TIM_SetCompare2(TIM2, C); }
void PWM_SetCompare3(uint16_t C){ TIM_SetCompare3(TIM2, C); }
