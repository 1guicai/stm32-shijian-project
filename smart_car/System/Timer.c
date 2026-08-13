#include "stm32f10x.h"
#include "Timer.h"
volatile uint16_t Timer_Tick = 0;
void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseInitTypeDef T;
	T.TIM_ClockDivision = TIM_CKD_DIV1;
	T.TIM_CounterMode = TIM_CounterMode_Up;
	T.TIM_Period = 1000 - 1;
	T.TIM_Prescaler = 72 - 1;
	T.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &T);
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef N;
	N.NVIC_IRQChannel = TIM2_IRQn;
	N.NVIC_IRQChannelCmd = ENABLE;
	N.NVIC_IRQChannelPreemptionPriority = 2;
	N.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&N);
	TIM_Cmd(TIM2, ENABLE);
}
