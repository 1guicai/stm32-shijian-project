#ifndef __PID_H
#define __PID_H
#include <stdint.h>
typedef struct {
	float Kp, Ki, Kd;
	float Setpoint;
	float Integral;
	float LastErr;
	float OutMin, OutMax;
} PID_t;
void  PID_Init(PID_t *p, float Kp, float Ki, float Kd, float OutMin, float OutMax);
float PID_Step(PID_t *p, float Measure);
void  PID_SetTarget(PID_t *p, float Target);
void  PID_Reset(PID_t *p);
#endif
