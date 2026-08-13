#include "stm32f10x.h"
#include "OLED_Font.h"
#define OLED_W_SCL(x) GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(x))
#define OLED_W_SDA(x) GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(x))
void OLED_I2C_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode = GPIO_Mode_Out_OD;
	G.GPIO_Speed = GPIO_Speed_50MHz;
	G.GPIO_Pin = GPIO_Pin_8; GPIO_Init(GPIOB, &G);
	G.GPIO_Pin = GPIO_Pin_9; GPIO_Init(GPIOB, &G);
	OLED_W_SCL(1); OLED_W_SDA(1);
}
void OLED_I2C_Start(void){ OLED_W_SDA(1); OLED_W_SCL(1); OLED_W_SDA(0); OLED_W_SCL(0); }
void OLED_I2C_Stop(void) { OLED_W_SDA(0); OLED_W_SCL(1); OLED_W_SDA(1); }
void OLED_I2C_SendByte(uint8_t B)
{
	uint8_t i;
	for(i=0;i<8;i++){ OLED_W_SDA(!!(B & (0x80>>i))); OLED_W_SCL(1); OLED_W_SCL(0); }
	OLED_W_SCL(1); OLED_W_SCL(0);
}
void OLED_WriteCommand(uint8_t C){ OLED_I2C_Start(); OLED_I2C_SendByte(0x78); OLED_I2C_SendByte(0x00); OLED_I2C_SendByte(C); OLED_I2C_Stop(); }
void OLED_WriteData(uint8_t D)   { OLED_I2C_Start(); OLED_I2C_SendByte(0x78); OLED_I2C_SendByte(0x40); OLED_I2C_SendByte(D); OLED_I2C_Stop(); }
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));
	OLED_WriteCommand(0x00 | (X & 0x0F));
}
void OLED_Clear(void)
{
	uint8_t i, j;
	for(j = 0; j < 8; j++){ OLED_SetCursor(j, 0); for(i = 0; i < 128; i++) OLED_WriteData(0x00); }
}
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{
	uint8_t i;
	OLED_SetCursor((Line-1)*2,   (Column-1)*8);
	for(i=0;i<8;i++) OLED_WriteData(OLED_F8x16[Char-' '][i]);
	OLED_SetCursor((Line-1)*2+1, (Column-1)*8);
	for(i=0;i<8;i++) OLED_WriteData(OLED_F8x16[Char-' '][i+8]);
}
void OLED_ShowString(uint8_t Line, uint8_t Column, char *S)
{
	uint8_t i; for(i = 0; S[i] != '\0'; i++) OLED_ShowChar(Line, Column+i, S[i]);
}
uint32_t OLED_Pow(uint32_t X, uint32_t Y){ uint32_t R=1; while(Y--) R*=X; return R; }
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t N, uint8_t L)
{
	uint8_t i; for(i=0;i<L;i++) OLED_ShowChar(Line, Column+i, N/OLED_Pow(10, L-i-1)%10 + '0');
}
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t N, uint8_t L)
{
	uint8_t i; uint32_t N1;
	if(N >= 0){ OLED_ShowChar(Line, Column, '+'); N1 = N; }
	else      { OLED_ShowChar(Line, Column, '-'); N1 = -N; }
	for(i=0;i<L;i++) OLED_ShowChar(Line, Column+i+1, N1/OLED_Pow(10, L-i-1)%10+'0');
}
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t N, uint8_t L)
{
	uint8_t i, S;
	for(i=0;i<L;i++){ S = N/OLED_Pow(16, L-i-1)%16; OLED_ShowChar(Line, Column+i, S<10?S+'0':S-10+'A'); }
}
void OLED_Init(void)
{
	uint32_t i, j;
	for(i=0;i<1000;i++) for(j=0;j<1000;j++);
	OLED_I2C_Init();
	OLED_WriteCommand(0xAE);
	OLED_WriteCommand(0xD5); OLED_WriteCommand(0x80);
	OLED_WriteCommand(0xA8); OLED_WriteCommand(0x3F);
	OLED_WriteCommand(0xD3); OLED_WriteCommand(0x00);
	OLED_WriteCommand(0x40);
	OLED_WriteCommand(0xA1);
	OLED_WriteCommand(0xC8);
	OLED_WriteCommand(0xDA); OLED_WriteCommand(0x12);
	OLED_WriteCommand(0x81); OLED_WriteCommand(0xCF);
	OLED_WriteCommand(0xD9); OLED_WriteCommand(0xF1);
	OLED_WriteCommand(0xDB); OLED_WriteCommand(0x30);
	OLED_WriteCommand(0xA4);
	OLED_WriteCommand(0xA6);
	OLED_WriteCommand(0x8D); OLED_WriteCommand(0x14);
	OLED_WriteCommand(0xAF);
	OLED_Clear();
}
