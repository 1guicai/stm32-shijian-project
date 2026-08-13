#include "stm32f10x.h"
#include "MyI2C.h"
#include "MPU6050_Reg.h"
#define MPU6050_ADDRESS  0xD0

void MPU6050_WriteReg(uint8_t R, uint8_t D)
{
	MyI2C_Start(); MyI2C_SendByte(MPU6050_ADDRESS); MyI2C_ReceiveAck();
	MyI2C_SendByte(R); MyI2C_ReceiveAck();
	MyI2C_SendByte(D); MyI2C_ReceiveAck(); MyI2C_Stop();
}
uint8_t MPU6050_ReadReg(uint8_t R)
{
	uint8_t D;
	MyI2C_Start(); MyI2C_SendByte(MPU6050_ADDRESS); MyI2C_ReceiveAck();
	MyI2C_SendByte(R); MyI2C_ReceiveAck();
	MyI2C_Start(); MyI2C_SendByte(MPU6050_ADDRESS|0x01); MyI2C_ReceiveAck();
	D = MyI2C_ReceiveByte(); MyI2C_SendAck(1); MyI2C_Stop();
	return D;
}

void MPU6050_Init(void)
{
	MyI2C_Init();
	MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01);
	MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00);
	MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x09);
	MPU6050_WriteReg(MPU6050_CONFIG, 0x06);
	MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18);
	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18);
}
uint8_t MPU6050_GetID(void){ return MPU6050_ReadReg(MPU6050_WHO_AM_I); }

void MPU6050_GetData(int16_t *AX,int16_t *AY,int16_t *AZ,int16_t *GX,int16_t *GY,int16_t *GZ)
{
	uint8_t H,L;
	H=MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H); L=MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L); *AX=(H<<8)|L;
	H=MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H); L=MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L); *AY=(H<<8)|L;
	H=MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H); L=MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L); *AZ=(H<<8)|L;
	H=MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);  L=MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);  *GX=(H<<8)|L;
	H=MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);  L=MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);  *GY=(H<<8)|L;
	H=MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);  L=MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);  *GZ=(H<<8)|L;
}
int16_t MPU6050_GetTemp(void)
{
	uint8_t H=MPU6050_ReadReg(MPU6050_TEMP_OUT_H), L=MPU6050_ReadReg(MPU6050_TEMP_OUT_L);
	return (int16_t)((H<<8)|L);
}
float MPU6050_GetTemperatureCelsius(void){ return (float)MPU6050_GetTemp()/340.0f+36.53f; }
