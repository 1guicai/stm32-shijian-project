#include "stm32f10x.h"
void Delay_us(uint32_t us)
{
	SysTick->LOAD = 72 * us;
	SysTick->VAL = 0;
	SysTick->CTRL = 0x00000005;
	while ((SysTick->CTRL & 0x00010000) == 0);
	SysTick->CTRL = 0x00000004;
}
void Delay_ms(uint32_t ms){ while(ms--) Delay_us(1000); }
void Delay_s(uint32_t s)   { while(s--)  Delay_ms(1000); }
