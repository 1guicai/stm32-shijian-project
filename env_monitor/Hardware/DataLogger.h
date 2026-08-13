#ifndef __DATALOGGER_H
#define __DATALOGGER_H
#include <stdint.h>
#define DL_MAGIC         0xAA55U
#define DL_MAX_RECORDS   2000
#define DL_RECORD_SIZE   16
#define DL_SECTOR_SIZE   4096
#define DL_BASE_ADDR     0x000000

typedef struct
{
	uint16_t Year; uint8_t Month, Day, Hour, Minute, Second;
	uint8_t  _pad;
	int16_t  Temp_x100;
	int16_t  AccZ;
	uint16_t Checksum;
} DL_Record_t;

void     DL_Init(void);
uint8_t  DL_Append(const DL_Record_t *rec);
uint16_t DL_Count(void);
uint8_t  DL_Read(uint16_t idx, DL_Record_t *out);
void     DL_ClearAll(void);
uint16_t DL_ComputeChecksum(const DL_Record_t *rec);
#endif
