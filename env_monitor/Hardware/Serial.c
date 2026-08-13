#include "stm32f10x.h"
#include <stdio.h>
#include <stdarg.h>
char Serial_RxPacket[100];
uint8_t Serial_RxFlag;

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Mode=GPIO_Mode_AF_PP; G.GPIO_Pin=GPIO_Pin_9; G.GPIO_Speed=GPIO_Speed_50MHz; GPIO_Init(GPIOA,&G);
	G.GPIO_Mode=GPIO_Mode_IPU;   G.GPIO_Pin=GPIO_Pin_10; GPIO_Init(GPIOA,&G);
	USART_InitTypeDef U;
	U.USART_BaudRate=9600; U.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	U.USART_Mode=USART_Mode_Tx|USART_Mode_Rx; U.USART_Parity=USART_Parity_No;
	U.USART_StopBits=USART_StopBits_1; U.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&U);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef N; N.NVIC_IRQChannel=USART1_IRQn; N.NVIC_IRQChannelCmd=ENABLE;
	N.NVIC_IRQChannelPreemptionPriority=1; N.NVIC_IRQChannelSubPriority=1; NVIC_Init(&N);
	USART_Cmd(USART1,ENABLE);
}
void Serial_SendByte(uint8_t B){ USART_SendData(USART1,B); while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET); }
void Serial_SendArray(uint8_t *A,uint16_t L){ uint16_t i; for(i=0;i<L;i++) Serial_SendByte(A[i]); }
void Serial_SendString(char *S){ uint8_t i; for(i=0;S[i];i++) Serial_SendByte(S[i]); }
uint32_t Serial_Pow(uint32_t X,uint32_t Y){ uint32_t R=1; while(Y--) R*=X; return R; }
void Serial_SendNumber(uint32_t N,uint8_t L){ uint8_t i; for(i=0;i<L;i++) Serial_SendByte(N/Serial_Pow(10,L-i-1)%10+'0'); }
int fputc(int ch,FILE *f){ Serial_SendByte(ch); return ch; }
void Serial_Printf(char *format,...)
{
	char S[200]; va_list arg; va_start(arg,format); vsprintf(S,format,arg); va_end(arg); Serial_SendString(S);
}
void USART1_IRQHandler(void)
{
	static uint8_t Rs=0, p=0;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		uint8_t D=USART_ReceiveData(USART1);
		if(Rs==0){ if(D=='@'&&Serial_RxFlag==0){ Rs=1; p=0; } }
		else if(Rs==1){ if(D=='\r') Rs=2; else Serial_RxPacket[p++]=D; }
		else if(Rs==2){ if(D=='\n'){ Rs=0; Serial_RxPacket[p]='\0'; Serial_RxFlag=1; } }
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
