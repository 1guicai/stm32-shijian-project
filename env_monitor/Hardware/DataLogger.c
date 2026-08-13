#include "DataLogger.h"
#include "W25Q64.h"
#include <string.h>
#define HDR_ADDR    (DL_BASE_ADDR)
#define DATA_ADDR   (DL_BASE_ADDR + DL_SECTOR_SIZE)
static uint16_t g_count;
static uint8_t  g_ready;

uint16_t DL_ComputeChecksum(const DL_Record_t *r)
{
	uint16_t sum=0; const uint8_t *p=(const uint8_t*)r;
	uint16_t i;
	for(i=0;i<DL_RECORD_SIZE-2;i++) sum+=p[i];
	return sum;
}

static void DL_Serialize(const DL_Record_t *r, uint8_t *b)
{
	b[0]=(uint8_t)(r->Year&0xFF); b[1]=(uint8_t)((r->Year>>8)&0xFF);
	b[2]=r->Month; b[3]=r->Day; b[4]=r->Hour; b[5]=r->Minute; b[6]=r->Second; b[7]=r->_pad;
	int16_t t=r->Temp_x100; b[8]=(uint8_t)(t&0xFF); b[9]=(uint8_t)((t>>8)&0xFF);
	int16_t a=r->AccZ;     b[10]=(uint8_t)(a&0xFF); b[11]=(uint8_t)((a>>8)&0xFF);
	uint16_t c=DL_ComputeChecksum(r); b[12]=(uint8_t)(c&0xFF); b[13]=(uint8_t)((c>>8)&0xFF);
	b[14]=0; b[15]=0;
}
static void DL_Deserialize(const uint8_t *b, DL_Record_t *r)
{
	r->Year=(uint16_t)b[0]|((uint16_t)b[1]<<8);
	r->Month=b[2]; r->Day=b[3]; r->Hour=b[4]; r->Minute=b[5]; r->Second=b[6]; r->_pad=b[7];
	r->Temp_x100=(int16_t)((uint16_t)b[8]|((uint16_t)b[9]<<8));
	r->AccZ      =(int16_t)((uint16_t)b[10]|((uint16_t)b[11]<<8));
	r->Checksum  =(uint16_t)b[12]|((uint16_t)b[13]<<8);
}
static void DL_WriteHeader(void)
{
	uint8_t buf[4];
	buf[0]=(uint8_t)(DL_MAGIC&0xFF); buf[1]=(uint8_t)((DL_MAGIC>>8)&0xFF);
	buf[2]=(uint8_t)(g_count&0xFF);  buf[3]=(uint8_t)((g_count>>8)&0xFF);
	W25Q64_SectorErase(HDR_ADDR);
	W25Q64_PageProgram(HDR_ADDR, buf, 4);
}
static uint8_t DL_ReadHeader(void)
{
	uint8_t buf[4]; W25Q64_ReadData(HDR_ADDR, buf, 4);
	uint16_t magic=(uint16_t)buf[0]|((uint16_t)buf[1]<<8);
	g_count=(uint16_t)buf[2]|((uint16_t)buf[3]<<8);
	return (magic==DL_MAGIC)?1:0;
}
void DL_Init(void)
{
	W25Q64_Init();
	if(!DL_ReadHeader()){ g_count=0; DL_WriteHeader(); }
	if(g_count>DL_MAX_RECORDS) g_count=DL_MAX_RECORDS;
	g_ready=1;
}
uint8_t DL_Append(const DL_Record_t *rec)
{
	if(!g_ready) return 0;
	if(g_count>=DL_MAX_RECORDS) return 0;
	DL_Record_t tmp=*rec; tmp.Checksum=DL_ComputeChecksum(&tmp);
	uint8_t buf[DL_RECORD_SIZE]; DL_Serialize(&tmp, buf);
	uint32_t addr=DATA_ADDR+(uint32_t)g_count*DL_RECORD_SIZE;
	W25Q64_PageProgram(addr, buf, DL_RECORD_SIZE);
	g_count++; DL_WriteHeader(); return 1;
}
uint16_t DL_Count(void){ return g_count; }
uint8_t DL_Read(uint16_t idx, DL_Record_t *out)
{
	if(!g_ready || idx>=g_count) return 0;
	uint8_t buf[DL_RECORD_SIZE];
	uint32_t addr=DATA_ADDR+(uint32_t)idx*DL_RECORD_SIZE;
	W25Q64_ReadData(addr, buf, DL_RECORD_SIZE);
	DL_Deserialize(buf, out);
	if(DL_ComputeChecksum(out)!=out->Checksum) return 0;
	return 1;
}
void DL_ClearAll(void)
{
	uint8_t i;
	W25Q64_SectorErase(HDR_ADDR);
	for(i=1;i<=8;i++) W25Q64_SectorErase(HDR_ADDR+(uint32_t)i*DL_SECTOR_SIZE);
	g_count=0; DL_WriteHeader();
}
