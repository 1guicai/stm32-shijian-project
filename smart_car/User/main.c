#include "stm32f10x.h"
#include "Delay.h"
#include "Timer.h"
#include "OLED.h"
#include "Key.h"
#include "Motor.h"
#include "Encoder.h"
#include "CountSensor.h"
#include "Serial.h"
#include "PID.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { UI_SPEED = 0, UI_ODO } UI_Screen_t;
static UI_Screen_t g_screen = UI_SPEED;
static int16_t  g_target_spd = 0;
static int16_t  g_cur_spd    = 0;
static int16_t  g_pwm_out    = 0;
static PID_t    g_pid;
static uint32_t g_last_pid_tick = 0;
static uint32_t g_last_calc_tick = 0;
static uint32_t g_uptime_sec = 0;
static uint8_t  g_motor_en = 0;
static uint8_t  g_led_tick = 0;

#define PID_KP_DEFAULT   0.60f
#define PID_KI_DEFAULT   0.08f
#define PID_KD_DEFAULT   0.05f
#define SPD_SAMPLE_MS   100
#define PID_SAMPLE_MS    50

static void UI_DrawSpeed(void)
{
	OLED_ShowString(1,1,"TGT:    pulse/ ");
	OLED_ShowNum(1,5,(g_target_spd<0?(uint32_t)(-g_target_spd):(uint32_t)g_target_spd),4);
	OLED_ShowChar(1,9,(g_target_spd>=0?' ':'-'));
	OLED_ShowString(1,11,"100ms");
	OLED_ShowString(2,1,"SPD:");
	OLED_ShowSignedNum(2,5,g_cur_spd,5);
	OLED_ShowString(2,11,"   ");
	OLED_ShowString(3,1,"PWM:");
	OLED_ShowSignedNum(3,5,g_pwm_out,4);
	OLED_ShowChar(3,10,'%');
	OLED_ShowString(4,1,"MOT:");
	OLED_ShowChar(4,5,g_motor_en?'O':'X');
	OLED_ShowString(4,7," T=");
	OLED_ShowNum(4,10,g_uptime_sec,5);
}
static void UI_DrawOdo(void)
{
	uint32_t pulses = CountSensor_GetTotal();
	OLED_ShowString(1,1,"=== ODOMETER ===");
	OLED_ShowString(2,1,"Pulse:          ");
	OLED_ShowNum(2,7,pulses,8);
	OLED_ShowString(3,1,"Up   :          ");
	OLED_ShowNum(3,7,g_uptime_sec/60,4); OLED_ShowChar(3,11,'m');
	OLED_ShowNum(3,12,(g_uptime_sec%60)/10,1); OLED_ShowNum(3,13,(g_uptime_sec%60)%10,1);
	OLED_ShowChar(3,14,'s');
	OLED_ShowString(4,1,"ENC Last:       ");
	OLED_ShowSignedNum(4,10,g_cur_spd,5);
}
static void Serial_ParseCmd(void)
{
	char *p = Serial_RxPacket;
	if(strncmp(p,"HELP",4)==0){
		Serial_Printf("=SMART CAR CMD=\r\n");
		Serial_Printf("HELP           Help\r\n");
		Serial_Printf("RUN=xx         Tgt pulse/100ms +/-300\r\n");
		Serial_Printf("STOP           Motor off\r\n");
		Serial_Printf("ENA            Motor + PID enable\r\n");
		Serial_Printf("SPD?           Cur spd & PWM\r\n");
		Serial_Printf("ODO?           Odo & uptime\r\n");
		Serial_Printf("PID=Kp,Ki,Kd   Set PID\r\n");
		Serial_Printf("PID?           Show PID\r\n");
		Serial_Printf("RST_ODO        Reset odo\r\n");
	} else if(strncmp(p,"RUN=",4)==0){
		int v=atoi(p+4);
		if(v> 300)v= 300;
		if(v<-300)v=-300;
		g_target_spd=(int16_t)v;
		g_motor_en=1;
		PID_Reset(&g_pid);
		PID_SetTarget(&g_pid,(float)g_target_spd);
		Serial_Printf("OK RUN:%d\r\n",g_target_spd);
	} else if(strcmp(p,"STOP")==0){
		g_motor_en=0; g_target_spd=0; g_pwm_out=0; Motor_SetSpeed(0);
		Serial_Printf("OK STOP\r\n");
	} else if(strcmp(p,"ENA")==0){
		g_motor_en=1;
		Serial_Printf("OK ENA, cur_tgt=%d\r\n",g_target_spd);
	} else if(strncmp(p,"SPD?",4)==0){
		Serial_Printf("SPD:tgt=%d,cur=%d,pwm=%d\r\n",g_target_spd,g_cur_spd,g_pwm_out);
	} else if(strncmp(p,"ODO?",4)==0){
		Serial_Printf("ODO:pulse=%lu,up=%lus\r\n",
			(unsigned long)CountSensor_GetTotal(),(unsigned long)g_uptime_sec);
	} else if(strncmp(p,"PID=",4)==0){
		float kp,ki,kd;
		if(sscanf(p+4,"%f,%f,%f",&kp,&ki,&kd)==3){
			PID_Init(&g_pid,kp,ki,kd,-100.0f,100.0f);
			PID_SetTarget(&g_pid,(float)g_target_spd);
			Serial_Printf("OK PID:Kp=%.3f Ki=%.3f Kd=%.3f\r\n",kp,ki,kd);
		} else Serial_Printf("ERR bad PID\r\n");
	} else if(strncmp(p,"PID?",4)==0){
		Serial_Printf("PID:Kp=%.3f Ki=%.3f Kd=%.3f set=%.1f\r\n",
			g_pid.Kp,g_pid.Ki,g_pid.Kd,g_pid.Setpoint);
	} else if(strcmp(p,"RST_ODO")==0){
		CountSensor_Clear(); g_uptime_sec=0;
		Serial_Printf("OK RST_ODO\r\n");
	} else Serial_Printf("UNKNOWN CMD, HELP\r\n");
}
int main(void)
{
	OLED_Init(); Key_Init(); Motor_Init();
	Encoder_Init(); CountSensor_Init();
	Timer_Init(); Serial_Init();
	PID_Init(&g_pid,PID_KP_DEFAULT,PID_KI_DEFAULT,PID_KD_DEFAULT,-100.0f,100.0f);
	PID_SetTarget(&g_pid,0.0f);
	OLED_Clear();
	OLED_ShowString(1,1,"Smart Car Ready ");
	OLED_ShowString(2,1,"K1=NextScreen   ");
	OLED_ShowString(3,1,"K2=RUN+20 cycle ");
	OLED_ShowString(4,1,"Odo K2=RST      ");
	Delay_ms(1500); OLED_Clear();
	Serial_Printf("\r\n=== SMART CAR BOOT ===\r\n");
	Serial_Printf("PID default: Kp=%.2f Ki=%.2f Kd=%.2f\r\n",
		PID_KP_DEFAULT,PID_KI_DEFAULT,PID_KD_DEFAULT);
	Serial_Printf("Send @HELP\\r\\n for list\r\n");
	uint32_t last_sec_tick=0;
	while(1){
		if((uint16_t)(Timer_Tick-g_last_calc_tick)>=SPD_SAMPLE_MS){
			g_last_calc_tick=Timer_Tick;
			g_cur_spd=Encoder_GetDelta();
		}
		if((uint16_t)(Timer_Tick-g_last_pid_tick)>=PID_SAMPLE_MS){
			g_last_pid_tick=Timer_Tick;
			if(g_motor_en && (g_target_spd!=0)){
				float out=PID_Step(&g_pid,(float)g_cur_spd);
				g_pwm_out=(int16_t)out;
				Motor_SetSpeed(g_pwm_out);
			} else {
				g_pwm_out=0;
				Motor_SetSpeed(0);
			}
		}
		if((uint16_t)(Timer_Tick-last_sec_tick)>=1000){
			last_sec_tick=Timer_Tick;
			g_uptime_sec++;
			Serial_Printf("[%lu] TGT=%d CUR=%d PWM=%d PULSE=%lu\r\n",
				(unsigned long)g_uptime_sec,
				g_target_spd,g_cur_spd,g_pwm_out,
				(unsigned long)CountSensor_GetTotal());
		}
		g_led_tick++;
		if(g_led_tick>=50){
			g_led_tick=0;
			if(g_screen==UI_SPEED) UI_DrawSpeed(); else UI_DrawOdo();
		}
		uint8_t kn=Key_GetNum();
		if(kn==1){
			g_screen=(g_screen==UI_SPEED)?UI_ODO:UI_SPEED;
			OLED_Clear();
		} else if(kn==2){
			if(g_screen==UI_SPEED){
				if(!g_motor_en || g_target_spd==0){
					g_target_spd=20; g_motor_en=1; PID_Reset(&g_pid);
				} else {
					g_target_spd+=20;
					if(g_target_spd>100)      g_target_spd=-20;
					if(g_target_spd<-100)     { g_target_spd=0; g_motor_en=0; }
				}
				PID_SetTarget(&g_pid,(float)g_target_spd);
			} else {
				CountSensor_Clear(); g_uptime_sec=0;
			}
		}
		if(Serial_RxFlag){ Serial_RxFlag=0; Serial_ParseCmd(); }
		Delay_ms(5);
	}
}
