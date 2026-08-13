#include "PID.h"
void PID_Init(PID_t *p, float Kp, float Ki, float Kd, float OutMin, float OutMax)
{
	p->Kp=Kp; p->Ki=Ki; p->Kd=Kd;
	p->Setpoint=0.0f; p->Integral=0.0f; p->LastErr=0.0f;
	p->OutMin=OutMin; p->OutMax=OutMax;
}
void PID_SetTarget(PID_t *p, float Target){ p->Setpoint = Target; }
void PID_Reset(PID_t *p){ p->Integral=0.0f; p->LastErr=0.0f; }
float PID_Step(PID_t *p, float Measure)
{
	float Err = p->Setpoint - Measure;
	float Deriv = Err - p->LastErr;
	p->Integral += Err;
	if(p->Integral*p->Ki >  p->OutMax) p->Integral =  p->OutMax/p->Ki;
	if(p->Integral*p->Ki < -p->OutMax) p->Integral = -p->OutMax/p->Ki;
	float Out = p->Kp*Err + p->Ki*p->Integral + p->Kd*Deriv;
	if(Out > p->OutMax) Out = p->OutMax;
	if(Out < p->OutMin) Out = p->OutMin;
	p->LastErr = Err;
	return Out;
}
