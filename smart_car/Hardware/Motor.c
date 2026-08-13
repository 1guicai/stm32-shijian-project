#include "stm32f10x.h"
#include "PWM.h"
void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_Out_PP;
	G.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &G);
	PWM_Init();
}
void Motor_SetSpeed(int16_t Speed)
{
	if(Speed >  100) Speed =  100;
	if(Speed < -100) Speed = -100;
	if(Speed >= 0) {
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3((uint16_t)Speed * 200);
	} else {
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3((uint16_t)(-Speed) * 200);
	}
}
