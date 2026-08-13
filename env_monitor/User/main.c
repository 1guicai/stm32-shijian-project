#include "stm32f10x.h"
#include "Delay.h"
#include "MyRTC.h"
#include "OLED.h"
#include "Key.h"
#include "LED.h"
#include "MPU6050.h"
#include "Serial.h"
#include "DataLogger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { UI_MAIN=0, UI_IMU, UI_RECORD_INFO, UI_LOG_DETAIL } UI_Screen_t;
static UI_Screen_t g_screen = UI_MAIN;
static uint8_t  g_idle_cnt;
static uint8_t  g_recording = 0;
static uint8_t  g_temp_alarm = 0;
static int16_t  g_log_idx = 0;
#define TEMP_HIGH_THRESHOLD   5000
#define TEMP_LOW_THRESHOLD   -1000
#define RECORD_PERIOD_TICKS  60
static uint16_t g_record_tick = 0;
static int16_t  g_AX,g_AY,g_AZ,g_GX,g_GY,g_GZ;
static float    g_tempC;
static int16_t  g_tempX100;
static uint8_t  g_mpuOK;
static uint8_t  g_flashMID;
static uint16_t g_flashDID;

static void UI_RefreshMain(void)
{
	OLED_ShowString(1,1,"Date:XXXX-XX-XX");
	OLED_ShowNum(1,6,MyRTC_Time[0],4);
	OLED_ShowNum(1,11,MyRTC_Time[1],2); OLED_ShowNum(1,14,MyRTC_Time[2],2);
	OLED_ShowString(2,1,"Time:XX:XX:XX");
	OLED_ShowNum(2,6,MyRTC_Time[3],2); OLED_ShowNum(2,9,MyRTC_Time[4],2); OLED_ShowNum(2,12,MyRTC_Time[5],2);
	OLED_ShowString(3,1,"Temp:");
	if(g_mpuOK) {
		int16_t t=g_tempX100;
		if(t>=0){ OLED_ShowNum(3,6,(uint32_t)(t/100),2); OLED_ShowChar(3,8,'.'); OLED_ShowNum(3,9,(uint32_t)(abs(t)%100),2); OLED_ShowChar(3,11,'C'); }
		else    { OLED_ShowChar(3,6,'-'); OLED_ShowNum(3,7,(uint32_t)((-t)/100),2); OLED_ShowChar(3,9,'.'); OLED_ShowNum(3,10,(uint32_t)((-t)%100),2); OLED_ShowChar(3,12,'C'); }
		if(g_temp_alarm) OLED_ShowString(3,14,"ALM"); else OLED_ShowString(3,14,"   ");
	} else OLED_ShowString(3,6,"--N/A--");
	OLED_ShowString(4,1,"REC:"); OLED_ShowChar(4,5,g_recording?'Y':'N');
	OLED_ShowString(4,7," N="); OLED_ShowNum(4,10,DL_Count(),4);
}
static void UI_RefreshIMU(void)
{
	OLED_ShowString(1,1,"IMU 6-Axis       ");
	OLED_ShowString(2,1,"AX:"); OLED_ShowSignedNum(2,4,g_AX,6);
	OLED_ShowString(2,11,"GX:"); OLED_ShowSignedNum(2,14,g_GX,5);
	OLED_ShowString(3,1,"AY:"); OLED_ShowSignedNum(3,4,g_AY,6);
	OLED_ShowString(3,11,"GY:"); OLED_ShowSignedNum(3,14,g_GY,5);
	OLED_ShowString(4,1,"AZ:"); OLED_ShowSignedNum(4,4,g_AZ,6);
	OLED_ShowString(4,11,"GZ:"); OLED_ShowSignedNum(4,14,g_GZ,5);
}
static void UI_RefreshRecordInfo(void)
{
	OLED_ShowString(1,1,"Flash Info       ");
	OLED_ShowString(2,1,"MID:0x  DID:0x    ");
	OLED_ShowHexNum(2,5,g_flashMID,2); OLED_ShowHexNum(2,11,g_flashDID,4);
	OLED_ShowString(3,1,"Records:          ");
	OLED_ShowNum(3,9,DL_Count(),4); OLED_ShowChar(3,13,'/'); OLED_ShowNum(3,14,DL_MAX_RECORDS,4);
	OLED_ShowString(4,1,"KEY2=Next");
}
static void UI_RefreshLogDetail(void)
{
	DL_Record_t rec;
	OLED_ShowString(1,1,"Log #    /       ");
	OLED_ShowNum(1,6,(uint32_t)(g_log_idx+1),4); OLED_ShowNum(1,13,(uint32_t)DL_Count(),4);
	if(DL_Count()==0){ OLED_ShowString(2,1,"  (empty)        "); OLED_ShowString(3,1,"                 "); OLED_ShowString(4,1,"                 "); return; }
	if(g_log_idx<0) g_log_idx=0;
	if(g_log_idx>=(int16_t)DL_Count()) g_log_idx=(int16_t)DL_Count()-1;
	if(DL_Read((uint16_t)g_log_idx,&rec)) {
		OLED_ShowString(2,1,"                 ");
		OLED_ShowNum(2,1,rec.Year%100,2); OLED_ShowChar(2,3,'-');
		OLED_ShowNum(2,4,rec.Month,2); OLED_ShowChar(2,6,'-');
		OLED_ShowNum(2,7,rec.Day,2);   OLED_ShowChar(2,9,' ');
		OLED_ShowNum(2,10,rec.Hour,2); OLED_ShowChar(2,12,':'); OLED_ShowNum(2,13,rec.Minute,2);
		OLED_ShowString(3,1,"Temp:            ");
		int16_t t=rec.Temp_x100;
		if(t>=0){ OLED_ShowNum(3,6,t/100,2); OLED_ShowChar(3,8,'.'); OLED_ShowNum(3,9,abs(t)%100,2); }
		else   { OLED_ShowChar(3,6,'-'); OLED_ShowNum(3,7,(-t)/100,2); OLED_ShowChar(3,9,'.'); OLED_ShowNum(3,10,(-t)%100,2); }
		OLED_ShowString(4,1,"AZ:"); OLED_ShowSignedNum(4,4,rec.AccZ,6); OLED_ShowString(4,11,"KEY2=Next");
	} else { OLED_ShowString(2,1,"  checksum err!  "); OLED_ShowString(3,1,"                 "); OLED_ShowString(4,1,"                 "); }
}
static void SwitchScreenNext(void)
{
	switch(g_screen) {
		case UI_MAIN:         g_screen=UI_IMU; break;
		case UI_IMU:          g_screen=UI_RECORD_INFO; break;
		case UI_RECORD_INFO:  g_screen=UI_LOG_DETAIL; g_log_idx=0; break;
		case UI_LOG_DETAIL:   g_screen=UI_MAIN; break;
		default:              g_screen=UI_MAIN; break;
	}
	OLED_Clear();
}
static void DoRecordOnce(void)
{
	DL_Record_t rec;
	rec.Year=MyRTC_Time[0]; rec.Month=(uint8_t)MyRTC_Time[1]; rec.Day=(uint8_t)MyRTC_Time[2];
	rec.Hour=(uint8_t)MyRTC_Time[3]; rec.Minute=(uint8_t)MyRTC_Time[4]; rec.Second=(uint8_t)MyRTC_Time[5];
	rec._pad=0; rec.Temp_x100=g_tempX100; rec.AccZ=g_AZ; rec.Checksum=0;
	if(DL_Append(&rec)){ LED2_ON(); Delay_ms(20); LED2_OFF(); }
	else g_recording=0;
}
static void Serial_ParseCommand(void)
{
	char *p=Serial_RxPacket;
	if(strncmp(p,"HELP",4)==0) {
		Serial_Printf("=ENV MONITOR CMD=\r\n");
		Serial_Printf("HELP            This msg\r\n");
		Serial_Printf("TIME?           Read RTC\r\n");
		Serial_Printf("TIME=YYYY-MM-DD HH:MM:SS\r\n");
		Serial_Printf("TEMP? IMU?      Sensors\r\n");
		Serial_Printf("REC_ON/OFF/NOW  Record ctrl\r\n");
		Serial_Printf("LOG? [N] CLR    Log ops\r\n");
		Serial_Printf("DUMP            CSV all\r\n");
	} else if(strncmp(p,"TIME?",5)==0) {
		MyRTC_ReadTime();
		Serial_Printf("RTC:%04d-%02d-%02d %02d:%02d:%02d\r\n",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2],MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
	} else if(strncmp(p,"TIME=",5)==0) {
		int y,mo,d,h,mi,s;
		if(sscanf(p+5,"%d-%d-%d %d:%d:%d",&y,&mo,&d,&h,&mi,&s)==6) {
			MyRTC_Time[0]=(uint16_t)y; MyRTC_Time[1]=(uint16_t)mo; MyRTC_Time[2]=(uint16_t)d;
			MyRTC_Time[3]=(uint16_t)h; MyRTC_Time[4]=(uint16_t)mi; MyRTC_Time[5]=(uint16_t)s;
			MyRTC_SetTime(); Serial_Printf("OK, RTC set\r\n");
		} else Serial_Printf("ERR: bad format\r\n");
	} else if(strncmp(p,"TEMP?",5)==0) {
		if(g_mpuOK) Serial_Printf("TEMP:%.2f C\r\n",g_tempC); else Serial_Printf("TEMP:N/A\r\n");
	} else if(strncmp(p,"IMU?",4)==0) {
		if(g_mpuOK) Serial_Printf("IMU:AX=%d AY=%d AZ=%d GX=%d GY=%d GZ=%d\r\n",g_AX,g_AY,g_AZ,g_GX,g_GY,g_GZ);
		else Serial_Printf("IMU:N/A\r\n");
	} else if(strcmp(p,"REC_ON")==0)  { g_recording=1; g_record_tick=0; Serial_Printf("REC_ON\r\n"); }
	 else if(strcmp(p,"REC_OFF")==0) { g_recording=0; Serial_Printf("REC_OFF\r\n"); }
	 else if(strcmp(p,"REC_NOW")==0) { DoRecordOnce(); Serial_Printf("REC_NOW: total=%d\r\n",DL_Count()); }
	 else if(strncmp(p,"LOG?",4)==0) {
		int n=atoi(p+4);
		if(n<=0) Serial_Printf("LOG_COUNT:%d\r\n",DL_Count());
		else {
			DL_Record_t r;
			if(DL_Read((uint16_t)(n-1),&r))
				Serial_Printf("LOG[%d]:%04d-%02d-%02d %02d:%02d:%02d,Temp=%d.%02dC,AZ=%d\r\n",n,r.Year,r.Month,r.Day,r.Hour,r.Minute,r.Second,r.Temp_x100/100,abs(r.Temp_x100)%100,r.AccZ);
			else Serial_Printf("LOG[%d]:BAD\r\n",n);
		}
	} else if(strcmp(p,"CLR")==0) { DL_ClearAll(); Serial_Printf("CLR_DONE\r\n"); }
	 else if(strcmp(p,"DUMP")==0) {
		uint16_t i,n=DL_Count();
		Serial_Printf("NO,DATE,TIME,TEMP_C,AZ\r\n");
		for(i=0;i<n;i++) {
			DL_Record_t r; if(!DL_Read(i,&r)) continue;
			int t=r.Temp_x100;
			Serial_Printf("%d,%04d-%02d-%02d,%02d:%02d:%02d,%d.%02d,%d\r\n",i+1,r.Year,r.Month,r.Day,r.Hour,r.Minute,r.Second,t/100,abs(t)%100,r.AccZ);
		}
		Serial_Printf("END_DUMP\r\n");
	} else Serial_Printf("UNKNOWN CMD, send HELP\r\n");
}

int main(void)
{
	MyRTC_Init(); OLED_Init(); Key_Init(); LED_Init(); Serial_Init();
	DL_Init(); W25Q64_ReadID(&g_flashMID,&g_flashDID);
	MPU6050_Init();
	if(MPU6050_GetID()==0x68){ g_mpuOK=1; OLED_ShowString(1,1,"MPU6050 OK      "); }
	else { g_mpuOK=0; OLED_ShowString(1,1,"MPU6050 N/A     "); }
	Delay_ms(1000); OLED_Clear();
	Serial_Printf("\r\n=== ENV MONITOR BOOT ===\r\n");
	Serial_Printf("Flash: MID=0x%02X DID=0x%04X Records=%d\r\n",g_flashMID,g_flashDID,DL_Count());
	Serial_Printf("Send @HELP\\r\\n for cmd list\r\n");
	while(1) {
		Delay_ms(500); g_idle_cnt++;
		MyRTC_ReadTime();
		if(g_mpuOK) {
			MPU6050_GetData(&g_AX,&g_AY,&g_AZ,&g_GX,&g_GY,&g_GZ);
			g_tempC = MPU6050_GetTemperatureCelsius();
			g_tempX100 = (int16_t)(g_tempC*100.0f);
		}
		g_temp_alarm = (g_tempX100>TEMP_HIGH_THRESHOLD || g_tempX100<TEMP_LOW_THRESHOLD) ? 1 : 0;
		if(g_recording) {
			g_record_tick++;
			if(g_record_tick>=RECORD_PERIOD_TICKS){ g_record_tick=0; DoRecordOnce(); }
		}
		if((g_idle_cnt&1)==0) LED1_Turn();
		if(g_temp_alarm) LED2_ON(); else if(!g_recording) LED2_OFF();
		uint8_t kn=Key_GetNum();
		if(kn==1) SwitchScreenNext();
		else if(kn==2) {
			switch(g_screen) {
			case UI_MAIN:
				g_recording=!g_recording;
				if(g_recording){ g_record_tick=0; DoRecordOnce(); }
				break;
			case UI_LOG_DETAIL:
				g_log_idx++;
				if(g_log_idx>=(int16_t)DL_Count()) g_log_idx=0;
				break;
			default: break;
			}
		}
		if(Serial_RxFlag){ Serial_RxFlag=0; Serial_ParseCommand(); }
		switch(g_screen) {
			case UI_MAIN:        UI_RefreshMain();        break;
			case UI_IMU:         UI_RefreshIMU();         break;
			case UI_RECORD_INFO: UI_RefreshRecordInfo();  break;
			case UI_LOG_DETAIL:  UI_RefreshLogDetail();   break;
		}
	}
}
