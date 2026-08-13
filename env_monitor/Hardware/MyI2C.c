#include "stm32f10x.h"
#include "Delay.h"
void MyI2C_W_SCL(uint8_t v){ GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)v); Delay_us(10); }
void MyI2C_W_SDA(uint8_t v){ GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)v); Delay_us(10); }
uint8_t MyI2C_R_SDA(void)    { uint8_t v=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11); Delay_us(10); return v; }
void MyI2C_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_Out_OD;
	G.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &G);
	GPIO_SetBits(GPIOB, GPIO_Pin_10 | GPIO_Pin_11);
}
void MyI2C_Start(void)    { MyI2C_W_SDA(1); MyI2C_W_SCL(1); MyI2C_W_SDA(0); MyI2C_W_SCL(0); }
void MyI2C_Stop(void)     { MyI2C_W_SDA(0); MyI2C_W_SCL(1); MyI2C_W_SDA(1); }
void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i=0;i<8;i++){ MyI2C_W_SDA(!!(Byte&(0x80>>i))); MyI2C_W_SCL(1); MyI2C_W_SCL(0); }
}
uint8_t MyI2C_ReceiveByte(void)
{
	uint8_t i,B=0x00; MyI2C_W_SDA(1);
	for(i=0;i<8;i++){ MyI2C_W_SCL(1); if(MyI2C_R_SDA()) B|=(0x80>>i); MyI2C_W_SCL(0); }
	return B;
}
void MyI2C_SendAck(uint8_t A){ MyI2C_W_SDA(A); MyI2C_W_SCL(1); MyI2C_W_SCL(0); }
uint8_t MyI2C_ReceiveAck(void){ uint8_t A; MyI2C_W_SDA(1); MyI2C_W_SCL(1); A=MyI2C_R_SDA(); MyI2C_W_SCL(0); return A; }
