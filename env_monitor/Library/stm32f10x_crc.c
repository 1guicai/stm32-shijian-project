  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_crc.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the CRC firmware functions.
  8→  ******************************************************************************
  9→  * @attention
 10→  *
 11→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 12→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 13→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 14→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 15→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 16→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 17→  *
 18→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 19→  ******************************************************************************
 20→  */
 21→
 22→/* Includes ------------------------------------------------------------------*/
 23→#include "stm32f10x_crc.h"
 24→
 25→/** @addtogroup STM32F10x_StdPeriph_Driver
 26→  * @{
 27→  */
 28→
 29→/** @defgroup CRC 
 30→  * @brief CRC driver modules
 31→  * @{
 32→  */
 33→
 34→/** @defgroup CRC_Private_TypesDefinitions
 35→  * @{
 36→  */
 37→
 38→/**
 39→  * @}
 40→  */
 41→
 42→/** @defgroup CRC_Private_Defines
 43→  * @{
 44→  */
 45→
 46→/**
 47→  * @}
 48→  */
 49→
 50→/** @defgroup CRC_Private_Macros
 51→  * @{
 52→  */
 53→
 54→/**
 55→  * @}
 56→  */
 57→
 58→/** @defgroup CRC_Private_Variables
 59→  * @{
 60→  */
 61→
 62→/**
 63→  * @}
 64→  */
 65→
 66→/** @defgroup CRC_Private_FunctionPrototypes
 67→  * @{
 68→  */
 69→
 70→/**
 71→  * @}
 72→  */
 73→
 74→/** @defgroup CRC_Private_Functions
 75→  * @{
 76→  */
 77→
 78→/**
 79→  * @brief  Resets the CRC Data register (DR).
 80→  * @param  None
 81→  * @retval None
 82→  */
 83→void CRC_ResetDR(void)
 84→{
 85→  /* Reset CRC generator */
 86→  CRC->CR = CRC_CR_RESET;
 87→}
 88→
 89→/**
 90→  * @brief  Computes the 32-bit CRC of a given data word(32-bit).
 91→  * @param  Data: data word(32-bit) to compute its CRC
 92→  * @retval 32-bit CRC
 93→  */
 94→uint32_t CRC_CalcCRC(uint32_t Data)
 95→{
 96→  CRC->DR = Data;
 97→  
 98→  return (CRC->DR);
 99→}
100→
101→/**
102→  * @brief  Computes the 32-bit CRC of a given buffer of data word(32-bit).
103→  * @param  pBuffer: pointer to the buffer containing the data to be computed
104→  * @param  BufferLength: length of the buffer to be computed					
105→  * @retval 32-bit CRC
106→  */
107→uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength)
108→{
109→  uint32_t index = 0;
110→  
111→  for(index = 0; index < BufferLength; index++)
112→  {
113→    CRC->DR = pBuffer[index];
114→  }
115→  return (CRC->DR);
116→}
117→
118→/**
119→  * @brief  Returns the current CRC value.
120→  * @param  None
121→  * @retval 32-bit CRC
122→  */
123→uint32_t CRC_GetCRC(void)
124→{
125→  return (CRC->DR);
126→}
127→
128→/**
129→  * @brief  Stores a 8-bit data in the Independent Data(ID) register.
130→  * @param  IDValue: 8-bit value to be stored in the ID register 					
131→  * @retval None
132→  */
133→void CRC_SetIDRegister(uint8_t IDValue)
134→{
135→  CRC->IDR = IDValue;
136→}
137→
138→/**
139→  * @brief  Returns the 8-bit data stored in the Independent Data(ID) register
140→  * @param  None
141→  * @retval 8-bit value of the ID register 
142→  */
143→uint8_t CRC_GetIDRegister(void)
144→{
145→  return (CRC->IDR);
146→}
147→
148→/**
149→  * @}
150→  */
151→
152→/**
153→  * @}
154→  */
155→
156→/**
157→  * @}
158→  */
159→
160→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/