#include "stm32f10x.h"
#include "MySPI.h"
#include "W25Q64_Ins.h"
void W25Q64_Init(void){ MySPI_Init(); }
void W25Q64_ReadID(uint8_t *MID, uint16_t *DID)
{
	MySPI_Start(); MySPI_SwapByte(W25Q64_JEDEC_ID);
	*MID = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	*DID  = MySPI_SwapByte(W25Q64_DUMMY_BYTE) << 8;
	*DID |= MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	MySPI_Stop();
}
void W25Q64_WriteEnable(void){ MySPI_Start(); MySPI_SwapByte(W25Q64_WRITE_ENABLE); MySPI_Stop(); }
void W25Q64_WaitBusy(void)
{
	uint32_t T=100000;
	MySPI_Start(); MySPI_SwapByte(W25Q64_READ_STATUS_REGISTER_1);
	while((MySPI_SwapByte(W25Q64_DUMMY_BYTE)&0x01)==0x01){ T--; if(!T) break; }
	MySPI_Stop();
}
void W25Q64_PageProgram(uint32_t A, uint8_t *D, uint16_t C)
{
	uint16_t i;
	W25Q64_WriteEnable(); MySPI_Start();
	MySPI_SwapByte(W25Q64_PAGE_PROGRAM);
	MySPI_SwapByte(A>>16); MySPI_SwapByte(A>>8); MySPI_SwapByte(A);
	for(i=0;i<C;i++) MySPI_SwapByte(D[i]);
	MySPI_Stop(); W25Q64_WaitBusy();
}
void W25Q64_SectorErase(uint32_t A)
{
	W25Q64_WriteEnable(); MySPI_Start();
	MySPI_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	MySPI_SwapByte(A>>16); MySPI_SwapByte(A>>8); MySPI_SwapByte(A);
	MySPI_Stop(); W25Q64_WaitBusy();
}
void W25Q64_ReadData(uint32_t A, uint8_t *D, uint32_t C)
{
	uint32_t i; MySPI_Start();
	MySPI_SwapByte(W25Q64_READ_DATA);
	MySPI_SwapByte(A>>16); MySPI_SwapByte(A>>8); MySPI_SwapByte(A);
	for(i=0;i<C;i++) D[i]=MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	MySPI_Stop();
}
