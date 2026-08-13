#ifndef __COUNTSENSOR_H
#define __COUNTSENSOR_H
#include <stdint.h>
void CountSensor_Init(void);
uint32_t CountSensor_GetTotal(void);
void CountSensor_Clear(void);
#endif
