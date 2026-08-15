 1→/**
 2→  ******************************************************************************
 3→  * @file    stm32f10x_crc.h
 4→  * @author  MCD Application Team
 5→  * @version V3.5.0
 6→  * @date    11-March-2011
 7→  * @brief   This file contains all the functions prototypes for the CRC firmware 
 8→  *          library.
 9→  ******************************************************************************
10→  * @attention
11→  *
12→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
13→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
14→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
15→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
16→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
17→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
18→  *
19→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
20→  ******************************************************************************
21→  */
22→
23→/* Define to prevent recursive inclusion -------------------------------------*/
24→#ifndef __STM32F10x_CRC_H
25→#define __STM32F10x_CRC_H
26→
27→#ifdef __cplusplus
28→ extern "C" {
29→#endif
30→
31→/* Includes ------------------------------------------------------------------*/
32→#include "stm32f10x.h"
33→
34→/** @addtogroup STM32F10x_StdPeriph_Driver
35→  * @{
36→  */
37→
38→/** @addtogroup CRC
39→  * @{
40→  */
41→
42→/** @defgroup CRC_Exported_Types
43→  * @{
44→  */
45→
46→/**
47→  * @}
48→  */
49→
50→/** @defgroup CRC_Exported_Constants
51→  * @{
52→  */
53→
54→/**
55→  * @}
56→  */
57→
58→/** @defgroup CRC_Exported_Macros
59→  * @{
60→  */
61→
62→/**
63→  * @}
64→  */
65→
66→/** @defgroup CRC_Exported_Functions
67→  * @{
68→  */
69→
70→void CRC_ResetDR(void);
71→uint32_t CRC_CalcCRC(uint32_t Data);
72→uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength);
73→uint32_t CRC_GetCRC(void);
74→void CRC_SetIDRegister(uint8_t IDValue);
75→uint8_t CRC_GetIDRegister(void);
76→
77→#ifdef __cplusplus
78→}
79→#endif
80→
81→#endif /* __STM32F10x_CRC_H */
82→/**
83→  * @}
84→  */
85→
86→/**
87→  * @}
88→  */
89→
90→/**
91→  * @}
92→  */
93→
94→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/