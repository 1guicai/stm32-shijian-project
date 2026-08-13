#include "stm32f10x.h"
#include "CountSensor.h"
static volatile uint32_t g_count;
void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_IPU;
	G.GPIO_Pin = GPIO_Pin_14;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &G);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	EXTI_InitTypeDef E;
	E.EXTI_Line = EXTI_Line14;
	E.EXTI_Mode = EXTI_Mode_Interrupt;
	E.EXTI_Trigger = EXTI_Trigger_Falling;
	E.EXTI_LineCmd = ENABLE;
	EXTI_Init(&E);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef N;
	N.NVIC_IRQChannel = EXTI15_10_IRQn;
	N.NVIC_IRQChannelCmd = ENABLE;
	N.NVIC_IRQChannelPreemptionPriority = 1;
	N.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&N);
	g_count = 0;
}
uint32_t CountSensor_GetTotal(void){ return g_count; }
void CountSensor_Clear(void)       { g_count = 0; }
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line14) == SET) {
		g_count++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}
